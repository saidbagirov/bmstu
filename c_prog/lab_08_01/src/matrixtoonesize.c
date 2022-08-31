#include "../inc/matrixtosqr.h"
#include "../inc/inout.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **addcol(int **matrix, int *rows, int *cols)
{
    for (int i = 0; i < *rows; i++)
    {
        int *temp = realloc(matrix[i], (*cols + 1) * sizeof(int));
        if (!temp)
        {
            free_matrix(matrix, *rows);
            matrix = NULL;
            break;
        }
        matrix[i] = temp;
    }
    for (int i = 0; i < *rows; i++)
    {
        int max = matrix[i][0];
        for (int j = 1; j < *cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        matrix[i][*cols] = max;
    }
    (*cols)++;
    return matrix;
}

int **addrow(int **matrix, int *rows, int *cols)
{
    int **temp = realloc(matrix, (*rows + 1) * sizeof(int*));
    if (!temp)
    {
        free_matrix(matrix, *rows);
        matrix = NULL;
    }
    else
    {
        matrix = temp;
        matrix[*rows] = calloc(*cols, sizeof(int));
        if (!matrix[*rows])
        {
            free_matrix(matrix, *rows);
            matrix = NULL;
        }
        else
        {
            for (int j = 0; j < *cols; j++)
            {
                /*int*/float sum = 0;
                for (int i = 0; i < *rows; i++)
                {
                    sum += matrix[i][j];
                }
                matrix[*rows][j] = (int) floor(sum / *rows);
            }
            (*rows)++;
        }
    }
    return matrix;
}

int **matrixtoonesize(int **matrix, int *rows1, int *cols, int *rows2)
{
    int count = 0;
    while (*rows1 != *rows2)
    {
        count++;
        matrix = addrow(matrix, rows1, cols);
    }
    for (int i = 0; i < count; i++)
    {
        matrix = addcol(matrix, rows1, cols);
    }
    return matrix;
}