#ifndef __D_LIB_H__
#define __D_LIB_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define INCORR_ARGC 1
#define INCORR_FILE 2
#define INCORR_COUNT 3
#define FILTER_ERROR 4
#define EMPTY_RESULT 5

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif
#define ARR_DECL __cdecl

ARR_DLL int ARR_DECL output_func(int *start, int *end, char *out_file);
ARR_DLL int ARR_DECL key(const int *old_first, const int *old_last, int **new_first, int **new_last);
ARR_DLL int *ARR_DECL input_func(char *in_file, int *count);//*?
ARR_DLL int ARR_DECL comp(const int *i, const int *j);
ARR_DLL int ARR_DECL mysort(void *array, size_t count, size_t size, int (*comp)(const int *i, const int *j));

#endif