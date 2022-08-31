#include <stdio.h>
#define N 20
#define M 10
int input_number(int *number)
{
    if (scanf("%d", number) != 1)
        return 1;
    if (*number < 0 || *number > 9)
        return 1; 
    return 0;
}
int print_matrix(int *n, int *m, int (*a)[N][M])
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
int first_digit(int n)
{
    int k;
    do
    {
        k = n;
        n /= 10;
    }while (n);
    return k;
}
int input_matrix(int *n, int *m, int (*a)[N][M])
{
    if (scanf("%d %d", n, m) != 2)
        return 1;
    if (*n <= 0 || *n > M || *m <= 0 || *m > M)
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
int change_matrix(int *number, int *n, int *m, int (*a)[N][M])
{
    for (int i = 0; i < *n; i++)
    {
        int end = 0, start = 0;
        for (int j = 0; j < *m; j++)
        {
            if ((*a)[i][j] < 0)
            {
                int q = (*a)[i][j] * -1;
                if (first_digit(q) == *number)
                {
                    start++;
                }
                if (q % 10 == *number)
                {
                    end++;
                }
            }
            else
            {
                if (first_digit((*a)[i][j]) == *number)
                {
                    start++;
                }
                if ((*a)[i][j] % 10 == *number)
                {
                    end++;
                }
            }
        }
        if ((end == start) && (end != 0))
        {
            (*n)++;
            for (int ii = *n - 1; ii >= i + 1; ii--)
            {
                for (int jj = 0; jj < M; jj++)
                    (*a)[ii][jj] = (*a)[ii - 1][jj];
            }
            for (int jj = 0; jj < M; jj++)
                (*a)[i + 1][jj] = 100;
        }
    }
    return 0;
}
int main()
{
    int a[N][M];
    int number, n, m;
    if (input_matrix(&n, &m, &a))
        return 1;
    if (input_number(&number) != 0)
        return 1;
    change_matrix(&number, &n, &m, &a);
    print_matrix(&n, &m, &a);
}