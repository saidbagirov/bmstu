#include <stdio.h>
#define ARRAY_LENGTH 10
int sort_vibor(int (*a)[ARRAY_LENGTH], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        int i_min = i;
        for (int j = i + 1; j < *n; j++)
        {
            if ((*a)[j] < (*a)[i_min])
                i_min = j;
        }
        int vrem = (*a)[i];
        (*a)[i] = (*a)[i_min];
        (*a)[i_min] = vrem; 
    }
    return 0;
}
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
int main()
{
    int a[ARRAY_LENGTH], n;
    int result = scanarray(&a, &n);
    if (result != 0) 
    {
        printf("Error");
        return 1;
    }
    else
    {
        sort_vibor(&a, &n);
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    return 0;
}