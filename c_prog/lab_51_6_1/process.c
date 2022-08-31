#include <stdio.h>
#include "process.h"
int process(FILE *file, int *max)
{
    int count = 1, prev, curr, more_or_less;
    if (fscanf(file, "%d", &prev) == 1)
    {
        if (fscanf(file, "%d", &curr) == 1)
        {
            if (curr > prev)
            {
                more_or_less = 1;
                count++;
            }
            else if (curr < prev)
            {
                more_or_less = -1;
                count++;
            }
            else 
            {
                more_or_less = 0;
            }
            if (count > *max)
            {
                *max = count;
            }
            prev = curr;
            while (fscanf(file, "%d", &curr) == 1)
            {
                if (curr > prev)
                {
                    if (more_or_less == 1)
                    {
                        count++;
                    }
                    else 
                    {
                        count = 2;
                        more_or_less = 1;
                    }
                }
                else if (curr < prev)
                {
                    if (more_or_less == -1)
                    {
                        count++;
                    }
                    else
                    {
                        count = 2;
                        more_or_less = -1;
                    } 
                }
                else 
                {
                    count = 1;
                    more_or_less = 0;
                }
                if (count > *max)
                {
                    *max = count;
                }
                prev = curr;
            }
            return 0;
        }
        else 
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}