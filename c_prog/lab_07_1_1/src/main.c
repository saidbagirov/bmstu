#include <stdio.h>
#include <stdlib.h>
#include "../inc/error_codes.h"
#include "../inc/input_func.h"
#include "../inc/sort_func.h"
#include "../inc/output_func.h"
#include "../inc/filter_func.h"

int main(int argc, char **argv)
{
    int result = SUCCESS;
    if (!argv[1])
    {
        result = INCORR_ARGC;
    }
    else if (argc == 3)
    {
        char *in_file = argv[1];
        char *out_file = argv[2];
        int count = 0;
        int *array = input_func(in_file, &count);
        if (array == 0)
        {
            return INCORR_FILE;
        }
        mysort(array, count, sizeof(int), *comp);
        output_func(array, array + count, out_file);
        free(array);
    }
    else if (argc == 4)
    {
        if (argv[3][0] != 'f')
        {
            result = INCORR_ARGC;
        }
        else
        {
            char *in_file = argv[1];
            char *out_file = argv[2];
            int count = 0;
            int *new_array = NULL;
            int *new_array_end = NULL;
            int *array = input_func(in_file, &count);
            if (key(array, array + count, &new_array, &new_array_end) == SUCCESS)
            {
                mysort(new_array, new_array_end - new_array, sizeof(int), *comp);
                output_func(new_array, new_array_end, out_file);
                free(new_array);
                free(array);
            }
            else
            {
                free(array);
                result = FILTER_ERROR;
            }
        }
    }
    else
    {
        result = INCORR_ARGC;
    }
    return result;
}
