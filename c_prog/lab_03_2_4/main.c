#include <stdio.h>
#define N 10
int input_matrix(int *n, int *m, int (*a)[N][N])
{
    if (scanf("%d %d", n, m) != 2)
        return 1;
    if (*n != *m)
        return 1;
    if (*n <= 1 || *n > N)
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
int find_and_print_elem(int *n, int (*a)[N][N])
{
    int imax;
    int jmax;
    int k = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            if (i + j > *n - 1 && ((*a)[i][j] % 10 == 5 || (*a)[i][j] % 10 == -5))
            {
                imax = i;
                jmax = j;
                k = 1;
                break;
            }
        }
    }
    if (k == 0)
        return 1;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            if (i + j > *n - 1 && ((*a)[i][j] % 10 == 5 || (*a)[i][j] % 10 == -5) && (*a)[i][j] > (*a)[imax][jmax])
            {
                imax = i;
                jmax = j;
            }
        }
    }
    printf("%d", (*a)[imax][jmax]);
    return 0;
}
int main()
{
    int a[N][N];
    int n, m;
    if (input_matrix(&n, &m, &a) == 1)
        return 1;
    if (find_and_print_elem(&n, &a) == 1)
        return 1;
}