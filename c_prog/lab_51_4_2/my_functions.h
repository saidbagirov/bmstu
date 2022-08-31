#include <stdio.h>
#include <errno.h>
#include <string.h>
#ifndef __MY_FUNCTIONS_H__
#define __MY_FUNCTIONS_H__
int find_max_and_min(FILE *f, float *max, float *min);
int find_average(FILE *f, float *max, float *min, float *result);
#endif