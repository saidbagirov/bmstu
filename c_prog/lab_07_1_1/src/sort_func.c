#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/sort_func.h"
#include "../inc/error_codes.h"

int comp(const void *i, const void *j)
{
    const int *a = i, *b = j;
    return *a - *b;
}

void swap(void *a, void *b, size_t size)
{
    char *aa = a, *bb = b;
    do
    {
        char tmp = *aa;
        *aa++ = *bb;
        *bb++ = tmp;
    } while (--size > 0);
}

void mysort(void *array, size_t count, size_t size, int (*comp)(const void *i, const void *j))
{
    char *left = (char *) array + size;
    char *right = (char *) array + size * (count - 1);
    char *j;
    char *k = right;
    do
    {
        for (j = left; j <= right; j += size)
            if (comp(j - size, j) > 0)
            {
                swap(j - size, j, size);
                k = j;
            }
        right = k - size;
        for (j = right; j >= left; j -= size)
            if (comp(j - size, j) > 0)
            {
                swap(j - size, j, size);
                k = j;
            }
        left = k + size;
    }
    while (left <= right);
}