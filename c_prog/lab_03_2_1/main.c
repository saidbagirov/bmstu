#include <stdio.h>
#define N 10
int input_matrix(int *n, int *m, int (*a)[N][N])
{
    if (scanf("%d %d", n, m) != 2)
        return 1;
    if (*n <= 0 || *n > N || *m <= 0 || *m > N)
        return 1; 
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            count += scanf("%d", &(*a)[i][j]);
        }
    }
    if (count != *n * *m)
        return 1;
    return 0;
}
int print_array(int *m, int (*b)[N])
{
    for (int i = 0; i < *m; i++)
    {
        printf("%d ", (*b)[i]);
    }
    return 0;
}
int create_new_array(int *n, int *m, int (*a)[N][N], int (*b)[N])
{   if (*n == 1)
        for (int i = 0; i < *m; i++)
            (*b)[i] = 0;
    else 
        for (int j = 0; j < *m; j++)
        {
            int k = 0;
            for (int i = 1; i < *n; i++)
            {
                if (((*a)[i][j] * (*a)[i - 1][j] > 0) || (*a)[i][j] == 0 || (*a)[i - 1][j] == 0)
                {
                    k = 1;
                    break;
                }
            }
            if (k == 1)
                (*b)[j] = 0;
            else
                (*b)[j] = 1;
        }
    return 0;
}
int main()
{
    int a[N][N], b[N];
    int n, m;
    if (input_matrix(&n, &m, &a) != 0)
        return 1;
    create_new_array(&n, &m, &a, &b);
    print_array(&m, &b);
    return 0;
}
