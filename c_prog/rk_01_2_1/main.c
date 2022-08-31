#include <stdio.h>
#include <stdlib.h>
#define N 20
int input_matrix(int *n, int (*a)[N][N])
{
    if (scanf("%d", n) != 1)
        return 1;
    if (*n <= 0 || *n > N)
        return 1; 
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            count += scanf("%d", &(*a)[i][j]);
        }
    }
    if (count != *n * *n)
        return 1;
    return 0;
}
int find_diag(int (*a)[N][N], int n, int *index, int *r)
{
    for (int d = -n + 1; d < n; d++)
    {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j - i > d)
                {
                    s1 += (*a)[i][j];
                }
                else if (j - i < d)
                {
                    s2 += (*a)[i][j];
                }
            }
        }
        if (s1 == s2)
        {
            *index = d;
            *r += 1;
        }
    }
    return 0;
}
int printindex(int index, int r)
{
    if (r != 0)
    {
        printf("%d", index);
    }
    else
    {
        printf("-1");
    }
    return 0;
}
int main()
{
    int r = 0;
    int n, index;
    int a[N][N];
    if (input_matrix(&n, &a) == 1)
    {
        return 1;
    }
    find_diag(&a, n, &index, &r);
    index = abs(index - n + 1);
    printindex(index, r);
    return 0;
}
