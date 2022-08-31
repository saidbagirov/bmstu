#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 0.00000001
void proverka(int x1, int y1, int x2, int y2, int xa, int ya)
{
    if (fabsf((sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2))) - (sqrtf(powf(xa - x1, 2) + powf(ya - y1, 2)) + sqrtf(powf(xa - x2, 2) + powf(ya - y2, 2)))) < EPS)
        printf("1");
    else
        printf("0");
}
int main()
{
    int x1, y1, x2, y2, xa, ya;
    int col;
    col = scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &xa, &ya);
    if (col == 6 && (x1 != x2 || y1 != y2))
    {
        proverka(x1, y1, x2, y2, xa, ya);
        return 0;
    }
    else
        return 1;
}
