#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/my_functions.h"
#include "../inc/error_codes.h"



int main(int argc, char **argv)
{
    description_of_films *films;
    int count = 0;
    int result = SUCCESS;

    if (argc >= 3 && argc <= 4)
    {
        if (!(result = scanning(argv[1], &films, &count)))
        {   
            if (!(result = sorting(films, argv[2], count)))
            {
                if (argc == 3)
                    output_all(films, count);
                else if (argc == 4)
                {
                    int index = searching(films, argv[3], argv[2], count);
                    if (index >= 0)
                        output_one(films, count, index);
                    else if (index == -1)
                        printf("Not found");
                    else 
                        result = ARGS_ERROR;
                }
            }
            free(films);
        }
    }
    else 
        result = ARGS_ERROR;
    return result;
}