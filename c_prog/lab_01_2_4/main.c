#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t, h, m, s;
    scanf("%d", &t);
    h = t / 3600;
    m = (t % 3600) / 60;
    s = t - m * 60 - h * 3600;
    printf("%d %d %d", h, m, s);
    return 0;
}
