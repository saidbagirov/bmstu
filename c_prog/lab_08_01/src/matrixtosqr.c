#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/matrixtosqr.h"
#include "../inc/inout.h"

void free_matrix(int **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void searchmax(int **matrix, int *rows, int *cols, int *imax, int *jmax)
{
    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
        {
            if (matrix[i][j] > matrix[*imax][*jmax])
            {
                *imax = i;
                *jmax = j;
            }
        }
    }
}

int **deletecol(int **matrix, int *rows, int *cols, int jmax)
{
    for (int i = 0; i < *rows; i++)
    {
        for (int j = jmax; j < *cols - 1; j++)
        {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    (*cols)--;
    for (int i = 0; i < *rows; i++)
    {
        int *temp = realloc(matrix[i], *cols * sizeof(int));
        if (!temp)
        {
            free_matrix(matrix, *rows);
            matrix = NULL;
            break;
        }
        matrix[i] = temp;
    }
    return matrix;
}

int **deleterow(int **matrix, int *rows, int *cols, int imax)
{
    for (int i = imax; i < *rows - 1; i++)
    {
        memmove(matrix[i], matrix[i + 1], *cols * sizeof(int));
    }
    (*rows)--;
    free(matrix[*rows]);
    int **temp = realloc(matrix, *rows * sizeof(int*));
    if (!temp)
    {
        free_matrix(matrix, *rows);
        matrix = NULL;
    }
    else
    {
        matrix = temp;
    }
    return matrix;
}

int **matrixtosqr(int **matrix, int *rows, int *cols)
{
    if (*rows < *cols)
    {
        while (*rows < *cols)
        {
            int imax = 0, jmax = 0;
            searchmax(matrix, rows, cols, &imax, &jmax);
            matrix = deletecol(matrix, rows, cols, jmax);
        }
    }
    else if (*rows > *cols)
    {
        while (*rows > *cols)
        {
            int imax = 0, jmax = 0;
            searchmax(matrix, rows, cols, &imax, &jmax);
            matrix = deleterow(matrix, rows, cols, imax);
        }
    }
    return matrix;
}