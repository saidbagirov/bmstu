#include <stdio.h>
#include <math.h>
#define ARRAY_LENGTH 10
int scanarray(int *pa, int *n, int *count, int *count2)
{
    int key = 0;
    if (scanf("%d", n) != 1 || *n < 1 || *n > 10)
    {
        key = 1;
    }
    else 
    {
        int *begin = pa;
        for (int i = 0; i < *n; i++)
        {
            *count += scanf ("%d", pa);
            pa++;
        }
        if (*count != *n)
        {
            key = 1;
        }
        else 
        {
            pa = begin;
            *count = 0;
            for (int i = 0; i < *n; i++)
            {
                if (*pa < 0)
                {
                    *count2 = *count2 + 1;
                }
                else if (*pa > 0)
                {
                    *count = *count + 1;
                }
                pa++;
            }
            if ((*count == 0) || (*count2 == 0))
                key = 1;
        }
        pa = begin;
    }
    return key;      
}
int main()
{
    int a[ARRAY_LENGTH], n, count = 0, count2 = 0;
    int *pa = a;
    if (scanarray(pa, &n, &count, &count2) == 1)
    {
        printf("Input error.");
        return 1;
    }
    else 
    {
        int k;
        if (count > count2)
            k = count2;
        else
            k = count;
        int *pos_i, *otr_i;
        int s = 0; 
        int *palast = pa + n - 1;
        while (k > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (*pa < 0)
                {
                    otr_i = pa;
                    pa++;
                    break;
                }
                else
                    pa++;
            }
            for (int i = 0; i < n; i++)
            {
                if (*palast > 0)
                {
                    pos_i = palast;
                    palast--;
                    break;
                }
                else
                    palast--;
            }
            s += *otr_i * *pos_i;
            k--;
        }
        printf("%d", s);
    }
}