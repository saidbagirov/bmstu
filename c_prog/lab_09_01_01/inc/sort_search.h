#include "error_codes.h"
#ifndef __SORT_SEARCH_H__
#define __SORT_SEARCH_H__
int char_binnary_search(char *a, char **temp, int count);
void sort_char_name(description_of_films *films, int count);
void sort_char_title(description_of_films *films, int count);
void sort_int(description_of_films *films, int count);
int sorting(description_of_films *films, char *field, int count);
int int_binnary_search(int a, int *temp, int count);
int searching(description_of_films *films, char *key, char *field, int count);
#endif
