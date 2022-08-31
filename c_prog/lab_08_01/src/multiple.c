#include <stdio.h>
#include <stdlib.h>
#include "../inc/matrixtosqr.h"

int **compare_matrix(int **matrix1, int rows, int **matrix2)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix1[i][j] = matrix2[i][j];
        }
    }
    return matrix1;
}

int **exp_0(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }  
    return matrix;     
}

int **mul(int **matrix1, int rows, int **matrix2, int **first)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix1[i][j] = 0;
            for (int k = 0; k < rows; k++)
            {
                matrix1[i][j] += matrix2[i][k] * first[k][j];
            }
        }
    }
    return matrix1;
}

int **exponentation(int **matrix, int rows, int exp)
{
    if (exp == 0)
    {
        matrix = exp_0(matrix, rows);
    }
    else
    {
        int **temp = malloc(rows * sizeof(int*));
        int **first = malloc(rows * sizeof(int*));
        if (!temp || !first)
        {
            free_matrix(matrix, rows);
            matrix = NULL;
        }
        else
        {
            int count = 1;
            int status = 1;
            for (int i = 0; i < rows && status; i++)
            {
                temp[i] = calloc(rows, sizeof(int));
                first[i] = calloc(rows, sizeof(int));
                if (!temp[i] || !first[i])
                {
                    free_matrix(matrix, rows);
                    free_matrix(temp, rows);
                    free_matrix(first, rows);
                    matrix = NULL;
                    status = 0;
                }
            }
            compare_matrix(first, rows, matrix);
            while (count < exp)
            {
                temp = mul(temp, rows, matrix, first);
                matrix = compare_matrix(matrix, rows, temp);
                count++;
            }
        }
        free_matrix(temp, rows);
        free_matrix(first, rows);
    }
    return matrix;
}

int **multiple(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2)
{
    int **temp = malloc(rows1 * sizeof(int*));
    if (!temp)
    {
        free_matrix(matrix1, rows1);
        free_matrix(matrix2, rows2);
        matrix1 = NULL;
        matrix2 = NULL;
    }
    else
    {
        int result = 0;
        for (int i = 0; i < rows1 && result != 1; i++)
        {
            temp[i] = calloc(rows1, sizeof(int));
            if (!temp[i])
            {
                free_matrix(matrix1, rows1);
                free_matrix(matrix2, rows2);
                free_matrix(temp, rows1);
                matrix1 = NULL;
                temp = NULL;
                matrix2 = NULL;
                result = 1;
            }
        }
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
            {
                temp[i][j] = 0;
                for (int k = 0; k < cols1; k++)
                {
                    temp[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        free_matrix(matrix1, rows1);
        free_matrix(matrix2, rows2);
    }
    return temp;
}
