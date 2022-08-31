#ifndef __MATRIXTOONESIZE_H__
#define __MATRIXTOONESIZE_H__

#include <stdio.h>
#include <stdlib.h>
int **addcol(int **matrix, int *rows, int *cols);
int **addrow(int **matrix, int *rows, int *cols);
int **matrixtoonesize(int **matrix1, int *rows1, int *cols1, int *rows2);

#endif