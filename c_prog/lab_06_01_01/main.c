#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"



int main(int argc, char **argv)
{
    int result = 0;
    description_of_films films[MAX_COUNT_OF_STRUCT];
    int count = 0;
    if (argc == 3)
    {
        if (scanning(argv[1], films, &count) == 1)
        {
            result = 1;
        }
        else
        {
            sorting(films, argv[2], count);
            output_all(films, count);
        }
    }
    else if (argc == 4)
    {
        if (scanning(argv[1], films, &count) == 1)
        {
            result = 1;
        }
        else 
        {
            if (sorting(films, argv[2], count) == SEARCHING_ERROR)
            {
                result = 1;
            }
            else
            {
                int index = searching(films, argv[3], argv[2], count);
                if (index == SEARCHING_NOT_FOUND)
                {
                    printf("Not found");
                }
                else if (index != SEARCHING_ERROR)
                {
                    output_one(films, count, index);
                }
                else
                {
                    result = 1;
                }
            }
        }
    }
    else result = 1;
    return result;
}