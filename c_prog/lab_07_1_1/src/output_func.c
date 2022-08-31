#include <stdio.h>
#include <stdlib.h>
#include "../inc/output_func.h"

int output_func(int *start, int *end, char *out_file)
{
    FILE *f = fopen(out_file, "w");
    for (int i = 0; start + i != end; i++)
    {
        fprintf(f, "%d ", *(start + i));
    }
    fclose(f);
    return 0;
}
