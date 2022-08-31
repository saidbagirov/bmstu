#ifndef __MY_FUNCTIONS_H__
#define __MY_FUNCTIONS_H__
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define NAME_LEN 25
#define AUTHOR_LEN 25
#define MAX_COUNT_OF_STRUCT 16

#define SEARCHING_ERROR -2
#define SEARCHING_NOT_FOUND -1


typedef struct
{
    char name[NAME_LEN + 1];
    char author[AUTHOR_LEN + 1];
    int date;
} description_of_films;



int scanning(char *input_path, description_of_films films[MAX_COUNT_OF_STRUCT], int *count);

int charbinnarysearch(char a[NAME_LEN], char temp[MAX_COUNT_OF_STRUCT][NAME_LEN], int count);

int sorting(description_of_films films[MAX_COUNT_OF_STRUCT], char *field, int count);

int output_all(description_of_films films[MAX_COUNT_OF_STRUCT], int count);

int output_one(description_of_films films[MAX_COUNT_OF_STRUCT], int count, int index);

int intbinnarysearch(int a, int temp[MAX_COUNT_OF_STRUCT], int count);

int searching(description_of_films films[MAX_COUNT_OF_STRUCT], char *key, char *field, int count);


#endif