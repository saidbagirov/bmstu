#include <stdio.h>
#include <stdlib.h>
#include "../inc/input_func.h"
#include "../inc/error_codes.h"

int *input_func(char *in_file, int *count)
{ 
    int *result = NULL;
    FILE *f = fopen(in_file, "r");
    if (!f)
    {
        result = NULL;
    }
    else
    {
        int tmp = 0;
        while (fscanf(f, "%d", &tmp) == 1)
        {
            (*count)++;
        }
        if (*count < 1)
        {
            fclose(f);
            result = NULL;
        }
        else
        {
            int *array = malloc((*count + 1) * sizeof(int));
            fseek(f, 0, SEEK_SET);
            for (int i = 0; i < *count; i++)
            {
                fscanf(f, "%d", array + i);
            }
            fclose(f);
            result = array;
        }
    }
    return result;
    fclose(f);
}
