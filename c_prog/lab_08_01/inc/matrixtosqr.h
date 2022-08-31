#ifndef __MATRIXTOSQR_H__
#define __MATRIXTOSQR_H__

void free_matrix(int **matrix, int row);
void searchmax(int **matrix, int *rows, int *cols, int *imax, int *jmax);
int **deletecol(int **matrix, int *rows, int *cols, int jmax);
int **matrixtosqr(int **matrix, int *rows, int *cols);

#endif