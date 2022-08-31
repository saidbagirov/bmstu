#ifndef __MY_FUNCTIONS_H__
#define __MY_FUNCTIONS_H__


#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define AUTHOR_LEN 25



typedef struct description_of_films
{
    char name[NAME_LEN + 1];
    char author[AUTHOR_LEN + 1];
    int date;
} description_of_films;


int scanning(char *input_path, description_of_films **films, int *count);

int sorting(description_of_films *films, char *field, int count);

int output_all(description_of_films *films, int count);

int output_one(description_of_films *films, int count, int index);

int searching(description_of_films *films, char *key, char *field, int count);

int charbinnarysearch(char a[NAME_LEN], void *data, size_t offset, int count);

int intbinnarysearch(int a, void *data, size_t offset, int count);


#endif