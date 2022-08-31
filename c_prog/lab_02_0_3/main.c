#include <stdio.h>
#include <math.h>
#define ARRAY_LENGTH 10
void delete(int *a, int i, int *n)
{
    int j;
    for (j = i; j < *n - 1; j++)
        a[j] = a[j + 1];
    *n -= 1;
}
typedef enum 
{
    success,
    no_palindrom,
    wrong_input
} error_code;
int ispalindrom(int number)
{
    if (number >= 0 && number < 10)
        return 0;
    if (number < 0)
        return 1;
    int number_save = number, obratnoe = 0;
    while (number != 0)
    {
        obratnoe = (obratnoe * 10) + (number % 10);
        number /= 10;
    }
    if (obratnoe == number_save)
        return 0;
    else
        return 1;   
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
    for (int i = 0; i < n; i++)
        if (ispalindrom(a[i]) == 0)
        {
            delete(a, i, &n);
            i -= 1;  
        }
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        return 0;
    }
    return 1;
}    
