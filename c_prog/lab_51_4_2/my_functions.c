#include "my_functions.h"
#include <stdio.h>
int find_max_and_min(FILE *f, float *max, float *min)
{
    float num;
    if (fscanf(f, "%f", max) == 1)
    {
        *min = *max;
        while (fscanf(f, "%f", &num) == 1)
        {
            if (num < *min)
            {
                *min = num;
            }
            if (num > *max)
            {
                *max = num;
            }
        }
        return 0;
    }
    return 1;
}
int find_average(FILE *f, float *max, float *min, float *result)
{
    float num;
    while (1)
    {
        fscanf(f, "%f", &num);
        if (num == *min || num == *max)
        {
            break;
        }
    }
    float sum = 0;
    int count = 0;
    while (1)
    {
        fscanf(f, "%f", &num);
        if (num == *min || num == *max)
        {
            break;
        }
        else
        {
            sum += num;
            count++;
        }
    }
    if (count != 0)
    {
        *result = sum / count;
    }
    return 0;
}