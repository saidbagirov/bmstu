#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef __MY_FUNCTIONS_H__
#define STR_LEN 100
#define STR_COUNT 100
#define __MY_FUNCTIONS_H__
int read_array(char *path, int n[STR_COUNT], int a[STR_COUNT][STR_LEN]);
int sort_array(int a[STR_COUNT][STR_LEN], int n[STR_COUNT], int count);
int print_in_file(int a[STR_COUNT][STR_LEN], char *path, int count, int n[STR_COUNT]);
int print_error(char *path);
#endif