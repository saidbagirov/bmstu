#include <stdio.h>
#include <string.h>
#include <stdint.h>
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
int input_all(char *input_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count)
{ 
    FILE *f;
    f = fopen(input_path, "r");
    if (!f)
    {
        return 1;
    }
    for (int i = 0; i < MAX_COUNT_OF_PRODUCTS; i++)
    {
        for (int j = 0; j < NAME_LEN + 2; j++)
        {
            products[i].name[j] = '\0';
        }
        for (int j = 0; j < PRODUCER_LEN + 2; j++)
        {
            products[i].producer[j] = '\0';
        }
        products[i].price = 0;
        products[i].value = 0;
    }
    for (int i = 0; !feof(f); i++)
    {
        fgets(products[i].name, NAME_LEN + 2, f);
        /*if (!fgets(products[i].name, NAME_LEN + 2, f))
        {
            return 1;
        }*/
        /*if (products[i].name[NAME_LEN + 1] != '\0')
        {
            return 1;
        }*/
        (*count)++;
        for (int j = 0; products[i].name[j] != '\0'; j++)
        {
            if (products[i].name[j] == '\n')
            {
                products[i].name[j] = '\0';
            }
            /*if (products[i].name[j] == '\r')
            {
                products[i].name[j] = '\0';
            }*/
        }
        if (products[i].name[0] == '\0')
        {
            return 1;
        }
        fgets(products[i].producer, PRODUCER_LEN + 2, f);
        /*if (!fgets(products[i].producer, PRODUCER_LEN + 2, f))
        {
            return 1;
        }*/
        /*if (products[i].producer[PRODUCER_LEN + 1] != '\0')
        {
            return 1;
        }*/
        (*count)++;
        for (int j = 0; products[i].producer[j] != '\0'; j++)
        {
            if (products[i].producer[j] == '\n')
            {
                products[i].producer[j] = '\0';
            }
            /*if (products[i].producer[j] == '\r')
            {
                products[i].producer[j] = '\0';
            }*/
        }
        if (products[i].producer[0] == '\0')
        {
            return 1;
        }
        if (fscanf(f, "%u\n", &products[i].price) != 1)
        {
            return 1;
        }
        (*count)++;
        if (fscanf(f, "%u\n", &products[i].value) != 1)
        {
            return 1;
        }
        (*count)++;
    }
    /*if (*count % 4)
    {
        return 1;
    }*/
    *count /= 4;
    /*if (*count > MAX_COUNT_OF_PRODUCTS)
    {
        return 1;
    }*/
    fclose(f);
    return 0;
}
void print_products(FILE *f, all_about_product products[MAX_COUNT_OF_PRODUCTS], int count)
{
    for (int i = 0; i < count; i++)
    {
        fprintf(f, "%s\n%s\n%u\n%u\n", products[i].name, products[i].producer, products[i].price, products[i].value);
        //printf("%s\n%s\n%u\n%u\n", products[i].name, products[i].producer, products[i].price, products[i].value);
    }
}
int sorting(char *input_path, char *output_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count)
{
    FILE *f_out;
    f_out = fopen(output_path, "w");
    /*if (!f_out)
    {
        return 1;
    }*/
    if (input_all(input_path, products, count))
    {
        return 1;
    }
    int check = 0;
    do
    {
        check = 0;
        for (int i = 0; i < *count - 1; i++)
        {
            if (products[i].price < products[i + 1].price)
            {
                all_about_product tmp;
                tmp = products[i];
                products[i] = products[i + 1];
                products[i + 1] = tmp;
                check = 1;
            }
            else if (products[i].price == products[i + 1].price)
            {
                if (products[i].value < products[i + 1].value)
                {
                    all_about_product tmp;
                    tmp = products[i];
                    products[i] = products[i + 1];
                    products[i + 1] = tmp;
                    check = 1;
                }
            }
        }
    }while (check);
    print_products(f_out, products, *count);
    fclose(f_out);
    return 0;
}
int search_by_end_of_name(char *input_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count, char str[NAME_LEN])
{
    if (input_all(input_path, products, count))
    {
        printf("!1");
        return 1;
    }
    if (strlen(str) > NAME_LEN)
    { 
        printf("!2");
        return 1;
    }
    int counter = 0;
    for (int i = 0; i < *count; i++)
    {
        if (strlen(products[i].name) >= strlen(str))
        {
            int k = strlen(products[i].name) - strlen(str);
            if (strncmp(&products[i].name[k], str, strlen(str)) == 0)
            {
                printf("%s\n%s\n%u\n%u\n", products[i].name, products[i].producer, products[i].price, products[i].value);
                counter++;
            }
        }
    }
    if (!counter)
    {
        return 1;
    }
    return 0;
}
int add_new_product(char *input_path, all_about_product products[MAX_COUNT_OF_PRODUCTS], int *count)
{
    int counter_tmp = 0;
    if (input_all(input_path, products, count))
    {
        return 1;
    }
    all_about_product tmp;
    if (!fgets(tmp.name, NAME_LEN + 2, stdin))
    {
        return 1;
    }
    if (tmp.name[strlen(tmp.name) - 1] != '\n')
    {
        return 1;
    }
    counter_tmp++;
    for (int j = 0; tmp.name[j] != '\0'; j++)
    {
        if (tmp.name[j] == '\n')
        {
            tmp.name[j] = '\0';
        }
        /*if (tmp.name[j] == '\r')
        {
            tmp.name[j] = '\0';
        }*/
    }
    if (!fgets(tmp.producer, PRODUCER_LEN + 2, stdin))
    {
        return 1;
    }
    if (tmp.producer[strlen(tmp.producer) - 1] != '\n')
    {
        return 1;
    }
    counter_tmp++;
    for (int j = 0; tmp.producer[j] != '\0'; j++)
    {
        if (tmp.producer[j] == '\n')
        {
            tmp.producer[j] = '\0';
        }
        /*if (tmp.name[j] == '\r')
        {
            tmp.name[j] = '\0';
        }*/
    }
    if (fscanf(stdin, "%u", &tmp.price) != 1)
    {
        return 1;
    }
    counter_tmp++;
    if (fscanf(stdin, "%u", &tmp.value) != 1)
    {
        return 1;
    }
    counter_tmp++;
    /*if (counter_tmp != 4)
    {
        return 1;
    }*/
    int i_search = -1;
    for (int i = 0; i < *count; i++)
    {
        if (products[i].price < tmp.price)
        {
            i_search = i;
            break;
        }
        else if (products[i].price == tmp.price)
        {
            if (products[i].value <= tmp.value)
            {
                i_search = i;
                break;
            }
        }
    }
    if (i_search == -1)
    {
        if (*count != 1)
        {
            i_search = *count - 1;
        }
        else
        {
            i_search = *count;
        }
    }
    for (int i = *count - 1; i >= i_search; i--)
    {
        products[i + 1] = products[i];
    }
    products[i_search] = tmp;
    FILE *f;
    f = fopen(input_path, "w");
    print_products(f, products, *count + 1);
    fclose(f);
    return 0;
}