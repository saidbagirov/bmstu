#include <stdio.h>
#include <math.h>
#define ARRAY_LENGTH 10
typedef enum
{
    success,
    wrong_input,
    no_positive
} error_code;
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
        if ((*a)[i] > 0)
            quantity += 1;
    }
    if (quantity == 0)
        return no_positive;
    return success;
}
int main()
{
    int a[ARRAY_LENGTH], n;
    error_code result = scanarray(&a, &n);
    if (result != success)
    {
        printf("Error");
        return 1;
    }
    else
    {
        int predproizv = 1;
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                val++; 
                predproizv *= a[i];
            }     
        }
        printf("%f", pow(predproizv, 1.0 / val));
    } 
    return 0; 
}