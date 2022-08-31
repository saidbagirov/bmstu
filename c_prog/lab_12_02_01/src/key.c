#include <stdlib.h>
#include <string.h>
#include "../inc/key.h"
#include "../inc/error_codes.h"



int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
	int result = SUCCESS;
	if (!pb_src || !pe_src || !pb_dst || !pe_dst) 
		result = MEMORY_ERROR;
	else
	{
		const int *p = pb_src;
		while (p < pe_src)
		{
			if (*p < 0) 
				break;
			p++;
		}

		size_t count = p - pb_src;
		if (!count) 
			result = EMPTY_RESULT;
		else
		{
			*pb_dst = malloc(count * sizeof(int));
			if (!*pb_dst) 
			{
				*pe_dst = NULL;
				result = MEMORY_ERROR;
			}
			else
			{
				*pe_dst = *pb_dst + count;

				memcpy(*pb_dst, pb_src, count * sizeof(int));
			}
		}
	}

	return result;
}