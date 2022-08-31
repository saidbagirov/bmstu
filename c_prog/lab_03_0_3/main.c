#include <stdio.h>
#define N 10
int sum_array(int n, int a[N])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
int print_matrix(int *n, int *m, int (*a)[N][N])
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            printf("%d ", ((*a)[i][j]));
        }
        printf("\n");
    }
    return 0;
}
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
int sort_matrix(int *n, int *m, int (*a)[N][N])
{
    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = 0; j < *n - 1; j++)
        {
            if (sum_array(*m, (*a)[j]) > (sum_array(*m, (*a)[j + 1])))
            {
                for (int h = 0; h < *m; h++)
                {
                    int tmp;
                    tmp = (*a)[j][h];
                    (*a)[j][h] = (*a)[j + 1][h];
                    (*a)[j + 1][h] = tmp;
                } 
            }
        }
    }
    return 0;
}
int main()
{
    int a[N][N];
    int n, m;
    if (input_matrix(&n, &m, &a) == 1)
        return 1;
    sort_matrix(&n, &m, &a);
    print_matrix(&n, &m, &a);
    return 0;
}