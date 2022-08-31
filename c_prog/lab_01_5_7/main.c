#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float summa(float x, float eps)
{
    float xcurr = 1;
    float summa_now = 1;
    int k1 = 1;
    int k2 = 2;
    while (xcurr > eps)
    {
        xcurr = xcurr * (k1 * powf(x, 2) / k2);
        summa_now = summa_now + xcurr;
        k1 = k1 + 2;
        k2 = k2 + 2;
    }
    return summa_now;
}
int main()
{
    float x, eps, sum;
    int col;
    float f, am, om;
    col = scanf("%f%f", &x, &eps);
    if (col == 2 && fabsf(x) < 1 && eps < 1)
    {
        sum = summa(x, eps);
        f = 1 / (sqrtf(1 - powf(x, 2)));
        am = fabsf(sum - f);
        om = fabsf((f - sum) / f);
        printf("%.6f %.6f %.6f %.6f", sum, f, am, om);
        return 0;
    }
    else
        return 1;
}
