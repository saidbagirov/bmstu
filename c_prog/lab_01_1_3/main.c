#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    float v1, t1, v2, t2, v3, t3;
    scanf("%f%f%f%f", &v1, &t1, &v2, &t2);
    v3 = v1 + v2;
    t3 = (v2 * t2 + v1 * t1) / v3;
    printf("%f %f", v3, t3);
    return 0;
}
