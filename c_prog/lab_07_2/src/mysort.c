#include <stdlib.h>
#include <string.h>
#include "../inc/mysort.h"



void mysort(void *data, size_t num_elem, size_t size_elem, comparer cmp)
{
	unsigned char *byte_data = (unsigned char*)data;

	void *t = malloc(size_elem);
	for (size_t i = 1; i < num_elem; i++)
	{
		for (size_t j = 0; j < num_elem - i; j++)
		{
			size_t ind1 = j * size_elem;
			size_t ind2 = (j + 1) * size_elem;
			
			if ((*cmp)(byte_data + ind1, byte_data + ind2) > 0)
			{
				memcpy(t, byte_data + ind1, size_elem);
				memcpy(byte_data + ind1, byte_data + ind2, size_elem);
				memcpy(byte_data + ind2, t, size_elem);
			}
		}
	}
	free(t);
}

int cmp_fun(const void *l, const void *r)
{
	int li = *(int*)l;
	int ri = *(int*)r;
	int res = 0;
	if (li > ri) 
		res = 1;
	if (li < ri) 
		res = -1;
	return res;
}