#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    float a, b, h, d, c, p;
    scanf("%f%f%f", &a, &b, &h);
    d = fabsf((a - b) / 2);
    c = sqrt(pow(h, 2) + pow(d, 2));
    p = a + b + 2 * c;
    printf("%f", p);
    return 0;
}
