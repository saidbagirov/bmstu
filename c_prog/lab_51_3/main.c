#include <stdio.h>
#include <string.h>
#include "my_functions.h"
int main(int argc, char **argv)
{
    if (strcmp(argv[1], "c") == 0 && argc == 4)
    {
        return random_nums(argv[3], *argv[2] - '0');
    }
    else if (strcmp(argv[1], "p") == 0 && argc == 3)
    {
        return print_nums(argv[2]);
    }
    else if (strcmp(argv[1], "s") == 0 && argc == 3)
    {
        return sorting(argv[2]);
    }
    else
    {
        return 1;
    }
}