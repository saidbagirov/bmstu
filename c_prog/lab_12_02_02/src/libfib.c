#include "../inc/libfib.h"



void fill_fib(int *arr, size_t len)
{
    if (len > 0) arr[0] = 0;
    if (len > 1) arr[1] = 1;
    for (size_t i = 2; i < len; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
}
size_t copy_unique(const int *src, size_t src_len, int *dst)
{
    size_t len = 0;
    for (size_t i = 0; i < src_len; i++)
    {
        int first = 1;
        for (size_t j = 0; j < i; j++)
        {
            if (src[j] == src[i])
            {
                first = 0;
                break;
            }
        }
        if (first)
        {
            if (dst) dst[len] = src[i];
            len++;
        }
    }
    return len;
}