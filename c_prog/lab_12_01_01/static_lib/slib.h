#ifndef __SLIB_H__
#define __SLIB_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define INCORR_ARGC 1
#define INCORR_FILE 2
#define INCORR_COUNT 3
#define FILTER_ERROR 4
#define EMPTY_RESULT 5

int output_func(int *start, int *end, char *out_file);
int key(const int *old_first, const int *old_last, int **new_first, int **new_last);
int *input_func(char *in_file, int *count);//*?
int comp(const int *i, const int *j);
int mysort(void *array, size_t count, size_t size, int (*comp)(const int *i, const int *j));

#endif