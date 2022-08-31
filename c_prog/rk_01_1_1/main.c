#include <stdio.h>
#define ARRAY_LENGTH 20
int scanarray (int (*a)[ARRAY_LENGTH], int *n)
{
    if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > ARRAY_LENGTH))
        return 1;
    int quantity = 0;
    for (int i = 0; i < *n; i++)
    {
        quantity += scanf ("%d", &(*a)[i]);
    }
    if (quantity != *n)
        return 1;
    return 0;
}
int make_new_array(int (*a)[ARRAY_LENGTH], int n, int (*b)[ARRAY_LENGTH], int p)
{
    int count = 0;
    int k = 0;
    int inew = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*a)[i] % p == 0)
        {
            k++;
        }
        if (k == 2)
        {
            k = 0;
            continue;
        }
        (*b)[inew] = (*a)[i];
        inew++;
        count++;
    }
    return count;
}
int printarray(int (*a)[ARRAY_LENGTH], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", (*a)[i]);
    }
    return 0;
}
int main()
{
    int n, count, p;
    int a[ARRAY_LENGTH];
    int new_array[ARRAY_LENGTH];
    if (scanarray(&a, &n) == 1)
    {
        return 1;
    }
    scanf("%d", &p);
    count = make_new_array(&a, n, &new_array, p);
    printarray(&new_array, count);
    return 0;
}