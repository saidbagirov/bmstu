#include <stdio.h>
#include <stdlib.h>
#include "../inc/inout.h"
#include "../inc/matrixtosqr.h"
#include "../inc/error_codes.h"
#include "../inc/matrixtoonesize.h"
#include "../inc/multiple.h"


int main()
{
    int cols1 = 0, rows1 = 0, cols2 = 0, rows2 = 0, exp1 = 0, exp2 = 0;
    int result = SUCCESS;
    int **matrix1 = input_func(&rows1, &cols1);
    if (matrix1 == NULL)
    {
        result = ERROR;
    }
    else
    {
        int **matrix2 = input_func(&rows2, &cols2);
        if (matrix2 == NULL)
        {
            free_matrix(matrix1, rows1);
            result = ERROR;
        }
        else
        {
            if (scanf("%d %d", &exp1, &exp2) != 2 || exp1 < 0 || exp2 < 0)
            {
                free_matrix(matrix1, rows1);
                free_matrix(matrix2, rows2);
                result = ERROR;
            }
            else
            {
                if (matrix1 && matrix2)
                {
                    matrix1 = matrixtosqr(matrix1, &rows1, &cols1);
                    matrix2 = matrixtosqr(matrix2, &rows2, &cols2);
                    if (matrix1 && matrix2)
                    {
                        if (rows1 < rows2)
                        {
                            matrix1 = matrixtoonesize(matrix1, &rows1, &cols1, &rows2);
                        }
                        else if (rows2 < rows1)
                        {
                            matrix2 = matrixtoonesize(matrix2, &rows2, &cols2, &rows1);
                        }
                        matrix1 = exponentation(matrix1, rows1, exp1);
                        matrix2 = exponentation(matrix2, rows2, exp2);
                        int **matrix3 = multiple(matrix1, rows1, cols1, matrix2, rows2, cols2);
                        output_func(matrix3, rows1, cols1);
                        free_matrix(matrix3, rows1);
                        result = SUCCESS;
                    }
                    else
                    {
                        result = ERROR;
                    }
                }
                else
                {
                    result = ERROR;
                }
            }
        }
    }
    return result;
}