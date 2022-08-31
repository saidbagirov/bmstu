#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nod_search(int a, int b)
{
    int nod;
    int q;
    if (a < b)
    {
        q = a;
        a = b;
        b = q;
    }
    for (int i = 1; i <= a ; i++)
        if (a % i == 0 && b % i == 0)
            nod = i;
    printf("%d", nod);
}

int main()
{
    int a, b;
    int col;
    col = scanf("%d%d", &a, &b);
    if (col == 2 && a > 0 && b > 0)
    {
        nod_search(a, b);
        return 0;
    }
    else
        return 1;
}
