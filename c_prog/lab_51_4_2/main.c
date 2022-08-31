#include <errno.h>
#include <stdio.h>
#include "my_functions.h"
int main(int argc, char **argv)
{
    FILE *f;
    f = fopen(argv[1], "r");
    if (!f)
    {
        fclose(f);
        fprintf(stderr, "Can't open file: %s", strerror(errno));
        return 1;
    }
    else
    {
        float max, min, result;
        if (find_max_and_min(f, &max, &min) == 1)
        {
            return 1;
        }
        rewind(f);
        find_average(f, &max, &min, &result);
        printf("%f", result);
        fclose(f);
        return 0;
    }
}