#include <stdio.h>
#include "process.h"
int main(void)
{
    int max = 1, error = process(stdin, &max);
    if (!error)
    {
        if (max != 1)
        {
            fprintf(stdout, "%d", max);
        }
        else
        {
            max = 0;
            fprintf(stdout, "%d", max);
        } 
    }
    return error;
}