#include <stdio.h>
#include <stdlib.h>
#include "../inc/filter_func.h"
#include "../inc/error_codes.h"

int key(const int *old_first, const int *old_last, int **new_first, int **new_last)
{
    int result = SUCCESS;
    if (old_first != NULL && old_last != NULL && new_first && new_last && old_first <= old_last)
    {
        int imax = 0;
        int imin = 0;
        int i = 0;
        while (old_first + i != old_last /*+ 1*/)
        {
            if (*(old_first + i) > *(old_first + imax))
            {
                imax = i;
            }
            if (*(old_first + i) < *(old_first + imin))
            {
                imin = i;
            }
            i++;
        }
        if (imax == imin + 1 || imax == imin - 1 || imax == imin)
        {
            result = EMPTY_RESULT;
        }
        else
        {
            if (imax < imin)
            {
                *new_first = malloc((imin - imax + 1) * sizeof(int));
                if (!new_first)
                {
                    result = EMPTY_RESULT;
                }
                else
                {
                    int j = 0;
                    for (int i = imax + 1; i != imin + 1; i++)
                    {
                        *(*new_first + j) = *(old_first + i);
                        j++;
                    }
                    *new_last = *new_first + j - 1;
                }
            }
            else if (imax > imin)
            {
                *new_first = malloc((imax - imin + 1) * sizeof(int));
                if (!new_first)
                {
                    result = EMPTY_RESULT;
                }
                else
                {
                    int j = 0;
                    for (int i = imin + 1; i != imax + 1; i++)
                    {
                        *(*new_first + j) = *(old_first + i);
                        j++;
                    }
                    *new_last = *new_first + j - 1;
                }
            }
        }   
    }
    else
    {
        result = FILTER_ERROR;
    }
    return result;
}
