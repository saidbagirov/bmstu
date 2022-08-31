#include <stdio.h>
#include <stdlib.h>
#ifndef __MY_FUNCTIONS_H__
#define __MY_FUNCTIONS_H__
int size_of_file(FILE *f, size_t *size);
int print_nums(char *path);
int get_number_by_pos(FILE *f, int pos);
int put_number_by_pos(FILE *f, int *num, int pos);
int sorting(char *path);
int random_nums(char *path, int count);
#endif