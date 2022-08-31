#include <stdio.h>
#include <math.h>
#define ARRAY_LENGTH 10
typedef enum 
{
    success,
    no_simple,
    wrong_input
} error_code;
int issimple(int m)
{
    int result = 0;
    if (m < 2)
        result = 1;
    else if (m > 2)
        for (int i = 2; i * i <= m; i++)
        {
            if (m % i == 0)
            {
                result = 1;
                break;
            }
        }
    return result;
}
error_code scanarray (int (*a)[ARRAY_LENGTH], int *n)
{
    if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > ARRAY_LENGTH))
        return wrong_input;
    int quantity = 0;
    for (int i = 0; i < *n; i++)
    {
        quantity += scanf ("%d", &(*a)[i]);
    }
    if (quantity != *n)
        return wrong_input;
    quantity = 0;
    for (int i = 0; i < *n; i++)
    {
        if (issimple((*a)[i]) == 0)
            quantity += 1;
    }
    if (quantity == 0)
        return no_simple;
    return success;
}
int main()
{
    int a[ARRAY_LENGTH], b[ARRAY_LENGTH], n;
    error_code result = scanarray(&a, &n);
    if (result != success) 
    {
        printf("Error");
        return 1;
    }
    else
    {
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (issimple(a[i]) == 0)
            {
                b[index] = a[i];
                index++;
            }
        }
        for (int i = 0; i < index; i++)
            printf("%d ", b[i]);
        return 0;
    }    
}
