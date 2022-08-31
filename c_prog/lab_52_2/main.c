#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "my_functions.h"
int main(int argc, char **argv)
{
    all_about_product products[MAX_COUNT_OF_PRODUCTS];
    int count = 0;
    int error_code = 53;
    //printf("argc = %d\n", argc);
    if (!argv[1])
    {
        return 53;
    }
    if (!strcmp(argv[1], "st") && argc >= 4)
    {
        if (!sorting(argv[2], argv[3], products, &count))
        {
            error_code = 0;
        }
        else
        {
            error_code = 1;
        }  
    }
    else if (!strcmp(argv[1], "ft") && argc >= 4)
    {
        if (!search_by_end_of_name(argv[2], products, &count, argv[3]))
        {
            error_code = 0;
        }
        else
        {
            error_code = 1;
        }   
    }
    else if (!strcmp(argv[1], "at") && argc >= 3)
    {
        if (!add_new_product(argv[2], products, &count))
        {
            error_code = 0;
        }
        else
        {
            error_code = 1;
        }
    }
    //printf("%d !!!\n", error_code);
    return error_code;
}