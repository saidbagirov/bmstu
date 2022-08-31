#include "slib.h"

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

int key(const int *old_first, const int *old_last, int **new_first, int **new_last)
{
    int result = SUCCESS;
    if (old_first != NULL && old_last != NULL && new_first && new_last && old_first <= old_last)
    {
        int imax = 0;
        int imin = 0;
        int i = 0;
        while (old_first + i != old_last + 1)
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
        // free(old_first);
    }
    else
    {
        result = FILTER_ERROR;
    }
    return result;
}

int *input_func(char *in_file, int *count)
{ 
    FILE *f = fopen(in_file, "r");
    if (!f)
    {
        //fclose(f);
        return 0;
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
            return 0;
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
            return array;
        }
    }
    fclose(f);
}

int comp(const int *i, const int *j)
{
    return *i - *j;
}

int mysort(void *array, size_t count, size_t size, int (*comp)(const int *i, const int *j))
{
    if (!array || count < 1)
        return EMPTY_RESULT;
    int *tmp = malloc(size);
    int *array1 = (int*) array;
    for (int i = 0; i < count - 1; i++)
    {
        int imax = i;
        for (int j = i + 1; j < count; j++)
        {
            if (comp(array1 + j, array1 + imax) < 0)
            {
                imax = j;
            }
        }
        if (imax != i)
        {
            memcpy(tmp, array1 + i, size);
            memcpy(array1 + i, array1 + imax, size);
            memcpy(array1 + imax, tmp, size);
        }
    }
    free(tmp);
    return SUCCESS;
}