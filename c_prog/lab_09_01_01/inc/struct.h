#ifndef __STRUCT_H__
#define __STRUCT_H__
#include "error_codes.h"
typedef struct
{
    char name[NAME_LEN + 1];
    char author[AUTHOR_LEN + 1];
    int date;
} description_of_films;
#endif
