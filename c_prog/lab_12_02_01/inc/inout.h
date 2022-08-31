#ifndef __INOUT_H__
#define __INOUT_H__
#include <stdio.h>

typedef struct array
{
	int size;
	int *data;
} array;
array create_array(size_t size);
array read_array(const char *file_path);
void write_array(const char *file_path, int *data, int size);
void dispose_array(array *a);

#endif
