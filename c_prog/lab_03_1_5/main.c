#include <stdio.h>
#define K 100
#define N 10
#define M 2
int shift_2(int (*a)[K])
{
    int tmp = (*a)[0];
    (*a)[0] = (*a)[1];
    (*a)[1] = tmp;
    return 0;
}
int print_matrix(int *n, int *m, int (*a)[N][N])
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            printf("%d ", ((*a)[i][j]));
        }
        printf("\n");
    }
    return 0;
}
int input_matrix(int *n, int *m, int (*a)[N][N])
{
    if (scanf("%d %d", n, m) != 2)
        return 1;
    if (*n <= 0 || *n > N || *m <= 0 || *m > N)
        return 1; 
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            count += scanf("%d", &(*a)[i][j]);
        }
    }
    if (count != *n * *m)
        return 1;
    return 0;
}
int sum_of_digits(int k)
{
    if (k < 0)
        k *= -1;
    int sum = 0;
    while (k > 0)
    {
        sum += k % 10;
        k /= 10;
    }
    return sum;
}
int shift_array_to_3(int n, int (*a)[K])
{
    int a0, a1, a2;
    a1 = (*a)[1];
    a2 = (*a)[2];
    a0 = (*a)[0];
    for (int i = 0; i < n - 3; i++)
    {
        (*a)[i] = (*a)[i + 3];
    }
    (*a)[n - 3] = a0;
    (*a)[n - 2] = a1;
    (*a)[n - 1] = a2;
    return 0;
}
int back_to_matrix(int (*a)[N][N], int (*ind)[K][M], int (*array)[K], int *v)
{
    for (int i = 0; i < *v; i++)
    {
        int itmp = (*ind)[i][0];
        int jtmp = (*ind)[i][1];
        (*a)[itmp][jtmp] = (*array)[i];
    }
    return 0;
}
int take_from_matrix(int *n, int *m, int (*a)[N][N], int (*ind)[K][M], int (*array)[K], int *v)
{
    *v = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (sum_of_digits((*a)[i][j]) > 10)
            {
                (*ind)[*v][0] = i;
                (*ind)[*v][1] = j;
                (*array)[*v] = (*a)[i][j];
                *v += 1;
            }
        }
    }
    return 0;
}
int main()
{
    int a[N][N], ind[K][M], array[K];
    int n, m, v;
    if (input_matrix(&n, &m, &a) == 1)
        return 1;
    take_from_matrix(&n, &m, &a, &ind, &array, &v);
    if (v > 3)
    {
        shift_array_to_3(v, &array);
        back_to_matrix(&a, &ind, &array, &v);
        print_matrix(&n, &m, &a);
    }
    else if (v == 2)
    {
        shift_2(&array);
        back_to_matrix(&a, &ind, &array, &v);
        print_matrix(&n, &m, &a);
    }
    else
    {
        print_matrix(&n, &m, &a);
    }
}