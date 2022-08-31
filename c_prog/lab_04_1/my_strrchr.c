#include "my_strrchr.h"
#include <stdio.h>
#include <string.h>
char *my_strrchr(char *a, char symbol)
{
    int i = 0;
    int tmp = -1;
    while (1)
    {
        if (a[i] == symbol)
        {
            tmp = i;
        }
        if (a[i] == '\0')
        {
            break;
        }
        i += 1;
    }
    if (tmp == -1)
        return NULL;
    char *isearch = &a[tmp];
    return isearch; 
}