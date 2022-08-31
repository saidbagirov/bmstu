#ifndef __MATRIX_H_
#define __MATRIX_H_
#include <stdlib.h>
#include <stdint.h>



typedef struct matrix 
{
    size_t w, h;
    int64_t *data;
} matrix;

matrix matrix_create(size_t w, size_t h);

void matrix_dispose(matrix *m);

matrix matrix_invalid();

matrix matrix_scan();

void matrix_print(const matrix *m);

int64_t matrix_valid(const matrix *m);

void matrix_set(matrix *m, const int64_t data[]);

int matrix_equeals(const matrix *l, const matrix *r);

int64_t matrix_get_elem(const matrix *m, size_t x, size_t y);

void matrix_set_elem(matrix *m, size_t x, size_t y, int64_t v);

void matrix_set_identy(matrix *m);

matrix matrix_multiply(const matrix *l, const matrix *r);

matrix matrix_power(const matrix *m, int64_t p);

void matrix_remove_row(matrix *m, size_t r);

void matrix_remove_col(matrix *m, size_t c);

void matrix_to_quad(matrix *m);

void matrix_enlarge(matrix *m, size_t s);

int matrix_fit(matrix *m1, matrix *m2);


#endif