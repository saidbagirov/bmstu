#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define NAME_LEN 30
#define PRODUCER_LEN 15
#define MAX_COUNT_OF_PRODUCTS 100
#pragma pack(push, 1)
typedef struct
{
    char name[NAME_LEN + 1];
    char producer[PRODUCER_LEN + 1];
    uint32_t price;
    uint32_t value;
} all_about_product;
#ifndef __MY_FUNCTIONS_H__
#define __MY_FUNCTIONS_H__
int input_all(char *input_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count);
void print_products(FILE *f, all_about_product products[MAX_COUNT_OF_PRODUCTS], int count);
int sorting(char *input_path, char *output_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count);
int search_by_end_of_name(char *input_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count, char str[NAME_LEN]);
int add_new_product(char *input_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count);
#endif
