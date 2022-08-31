#include <stdio.h>
#include <stdlib.h>
#include "../inc/inout.h"



array create_array(size_t size)
{
	array result;
	result.size = size;
	result.data = malloc(size * sizeof(int));;
	return result;
}

array read_array(const char *file_path)
{
	array result;
	result.data = NULL;
	result.size = 0;
	int size = 0, v;

	FILE* file = fopen(file_path, "r");
	if (file) 
	{
		while (fscanf(file, "%d", &v) == 1) 
			size++;
		if (size >= 1) 
		{
			result = create_array(size); 
			if (result.data) 
			{
				fseek(file, 0, SEEK_SET);
				for (int i = 0; i < size; i++)
					fscanf(file, "%d", result.data + i);
			}
		}

		fclose(file);
	}

	return result;
}

void write_array(const char *file_path, int *data, size_t size)
{
	FILE *file = fopen(file_path, "w");
	for (int i = 0; i < size; i++)
		fprintf(file, "%d ", data[i]);
	fclose(file);
}

void dispose_array(array *a)
{
	free(a->data);
}