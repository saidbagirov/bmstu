#include <stdio.h>
#include "my_strrchr.h"
#include <string.h>
int main()
{
    if (my_strrchr("", '2') != strrchr("", '2'))
        return 1;
    if (my_strrchr("good game well play", 'l') != strrchr("good game well play", 'l'))
        return 1;
    if (my_strrchr("012345", '2') != strrchr("012345", '2'))
        return 1;
    if (my_strrchr("012345", 'q') != strrchr("012345", 'q'))
        return 1;
    if (my_strrchr("012345", '9') != strrchr("012345", '9'))
        return 1;
    if (my_strrchr("How to do it?", 'H') != strrchr("How to do it?", 'H'))
        return 1;    
    return 0;
}