/*
Отсортировать матрицу в виде змейки, 
начинающейся из центра и раскручивающейся наружу
*/
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct matrix {
	int* cells;
	int w;
	int h;
} matrix;

matrix allocate_matrix(int w, int h)
{
	matrix result;
	result.w = w;
	result.h = h;
	result.cells = (int*)malloc(w * h * sizeof(int));
	return result;
}

void free_matrix(matrix m)
{
	free(m.cells);
}

int get_cell(matrix m, int x, int y)
{
	return m.cells[y * m.w + x];
}

void set_cell(matrix m, int x, int y, int v)
{
	m.cells[y * m.w + x] = v;
}

void sort(matrix m)
{
	for (int i = 1; i < m.w * m.h; i++)
	{
		for (int j = 0; j < m.w * m.h - i; j++)
		{
			if (m.cells[j] < m.cells[j + 1])
			{
				int t = m.cells[j];
				m.cells[j] = m.cells[j + 1];
				m.cells[j + 1] = t;
			}
		}
	}
}

matrix spiral_print(matrix mat)
{
	matrix result = allocate_matrix(mat.w, mat.h);
	int p = 0;
	int m = mat.h;
	int n = mat.w;
	int i, k = 0, l = 0;
	while (k < m && l < n) {
		for (i = l; i < n; ++i) {
			set_cell(result, i, k, mat.cells[p++]);
		}
		k++;
		for (i = k; i < m; ++i) {
			set_cell(result, n - 1, i, mat.cells[p++]);
		}
		n--;
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				set_cell(result, i, m - 1, mat.cells[p++]);
			}
			m--;
		}
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				set_cell(result, l, i, mat.cells[p++]);
			}
			l++;
		}
	}
	return result;
}

int main()
{
	int w, h, v;
	printf("Enter width and height of the matrix: ");
	scanf("%d %d", &w, &h);
	matrix mat = allocate_matrix(w, h);
	printf("Enter matrix:\n");
	for (int y = 0; y < mat.h; y++)
	{
		for (int x = 0; x < mat.w; x++)
		{
			scanf("%d", &v);
			set_cell(mat, x, y, v);
		}
	}
	printf("Entered matrix %dx%d:\n", w, h);
	for (int y = 0; y < mat.h; y++)
	{
		for (int x = 0; x < mat.w; x++)
		{
			printf("%4d", get_cell(mat, x, y));
		}
		printf("\n");
	}
	sort(mat);
	matrix new_mat = spiral_print(mat);
	printf("Result matrix %dx%d:\n", w, h);
	for (int y = 0; y < new_mat.h; y++)
	{
		for (int x = 0; x < new_mat.w; x++)
		{
			printf("%4d", get_cell(new_mat, x, y));
		}
		printf("\n");
	}
	free_matrix(mat);
	free_matrix(new_mat);
	return 0;
}