#include <stdio.h>
#include <stdlib.h>
#include "../inc/inout.h"
#include "../inc/error_codes.h"
#include "../inc/matrixtosqr.h"

int **input_func(int *rows, int *cols)
{
    int **matrix = NULL;
    if (scanf("%d %d", rows, cols) != 2 || *rows <= 1 || *cols <= 1)
    {
        matrix = NULL;
    }
    else
    {
        matrix = calloc((*rows), sizeof(int*));
        if (!matrix)
        {
            matrix = NULL;
        }
        else
        {
            for (int i = 0; i < *rows; i++)
            {
                int *temp = calloc((*cols), sizeof(int));
                if (!temp)
                {
                    free_matrix(matrix, *rows);
                    matrix = NULL;
                    break;
                }
                else
                {
                    free(temp);
                    matrix[i] = calloc((*cols), sizeof(int));
                    for (int j = 0; j < *cols; j++)
                    {
                        if (scanf("%d", &matrix[i][j]) != 1)
                        {
                            free_matrix(matrix, *rows);
                            matrix = NULL;
                            break;
                        }
                    }
                }
            }
        }
    }
    return matrix;
}

void output_func(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
