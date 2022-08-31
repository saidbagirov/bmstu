#include <stdio.h>
#include <stdlib.h>
#include "../inc/key.h"
#include "../inc/mysort.h"
#include "../inc/inout.h"
#include "../inc/error_codes.h"



int main(int argc, char **argv)
{
	int result = SUCCESS;
	if (argc < 3 || argc > 4) 
		result = ARGS_ERROR;
	else
	{
		char *in_file = argv[1];
		char *out_file = argv[2];
		int filter = 0;
		if (argc == 4 && argv[3][0] != 'f')
			result = ARGS_ERROR;
		else 
		{
			if (argc == 4) 
				filter = 1;

			array a = read_array(in_file);
			if (!a.data) 
				result = MEMORY_ERROR;
			else
			{
				if (filter) 
				{
					array b;
					int *end;
					result = key(a.data, a.data + a.size, &b.data, &end);
					b.size = end - b.data;
					dispose_array(&a);
					a = b;
				}
				if (result == SUCCESS)
				{
					mysort(a.data, a.size, sizeof(int), &cmp_fun);

					write_array(out_file, a.data, a.size);

					dispose_array(&a);
				}
			}
		}
	}

	return result;
}