#include "../inc/error_codes.h"
#include "../inc/struct.h"

int char_binnary_search(char *a, char **temp, int count)
{
    int low, high, middle = 0;
    low = 0;
    high = count - 1;
    int result = ERROR_IN_SEARCH;
    while (low <= high && result != middle)
    {
        middle = (low + high) / 2;
        if (strcmp(a, temp[middle]) < 0)
        {
            high = middle - 1;
        }
        else if (strcmp(a, temp[middle]) > 0)
        {
            low = middle + 1;
        }
        else
        {
            result = middle;
        }
    }
    return result;
}

void swap(description_of_films *elem1, description_of_films *elem2)
{
    description_of_films temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void sort_char_name(description_of_films *films, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j < count; j++)
        {
            if (strcmp(films[j].name, films[j - 1].name) < 0)
                swap(&films[j], &films[j - 1]);
        }
    }
}

void sort_char_title(description_of_films *films, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j < count; j++)
        {
            if (strcmp(films[j].author, films[j - 1].author) < 0)
                swap(&films[j], &films[j - 1]);
        }
    }
}

void sort_int(description_of_films *films, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j < count; j++)
        {
            if (films[j].date < films[j - 1].date)
                swap(&films[j], &films[j - 1]);
        }
    }    
}

int sorting(description_of_films *films, char *field, int count)
{
    int result = SUCCESS;
    if (strcmp(field, "title") == 0)
    {
        sort_char_name(films, count);
    }
    else if (strcmp(field, "name") == 0)
    {
        sort_char_title(films, count);
    }
    else if (strcmp(field, "year") == 0)
    {
        sort_int(films, count);
    }
    else 
    {
        result = ERROR_IN_SEARCH;
    }
    return result;
}

int int_binnary_search(int a, int *temp, int count)
{
    int result = ERROR_IN_SEARCH;
    int low, high, middle = 0;
    low = 0;
    high = count - 1;
    while (low <= high && result != middle)
    {
        middle = (low + high) / 2;
        if (a < temp[middle])
        {
            high = middle - 1;
        }
        else if (a > temp[middle])
        {
            low = middle + 1;
        }
        else
        {
            result = middle;
        }
    }
    return result;
}

int searching_title(description_of_films *films, char *key, char *field, int count)
{
    int result = SUCCESS;
    char **temp = calloc(MAX_COUNT_OF_STRUCT, sizeof(char*));
    if (!temp)
    {
        result = MEMORY_ERROR;
    }
    else
    {
        for (int j = 0; j < MAX_COUNT_OF_STRUCT; j++)
        {
            if (result == MEMORY_ERROR)
            {
                continue;
            }
            else
            {
                temp[j] = calloc(NAME_LEN, sizeof(char));
                if (!temp[j])
                {
                    for (int i = 0; i < j; i++)
                    {                
                        free(temp[i]);
                    }
                    free(temp);
                    result = MEMORY_ERROR;
                }
            }
        }
        if (result != MEMORY_ERROR)
        {
            for (int i = 0; i < count; i++)
            {
                strcpy(temp[i], films[i].name);
            }
            int index = char_binnary_search(key, temp, count);
            result = index;
            for (int i = 0; i < MAX_COUNT_OF_STRUCT; i++)
            {
                free(temp[i]);
            }
            free(temp);
        }
    }
    return result;
}

int searching_name(description_of_films *films, char *key, char *field, int count)
{
    int result = SUCCESS;
    char **temp = calloc(MAX_COUNT_OF_STRUCT, sizeof(char*));
    if (!temp)
    {
        result = MEMORY_ERROR;
    }
    else
    {
        for (int j = 0; j < MAX_COUNT_OF_STRUCT && result != MEMORY_ERROR; j++)
        {
            temp[j] = calloc(AUTHOR_LEN, sizeof(char));
            if (!temp[j])
            {
                for (int i = 0; i < j; i++)
                {                
                    free(temp[i]);
                }
                free(temp);
                result = MEMORY_ERROR;
            } 
        }
        if (result != MEMORY_ERROR)
        {
            for (int i = 0; i < count; i++)
            {
                strcpy(temp[i], films[i].author);
            }
            int index = char_binnary_search(key, temp, count);
            result = index;
            for (int i = 0; i < MAX_COUNT_OF_STRUCT; i++)
            {
                free(temp[i]);
            }
            free(temp);
        }   
    }
    return result;
}

int searching_year(description_of_films *films, char *key, char *field, int count)
{
    int result = SUCCESS;
    int *temp = calloc(MAX_COUNT_OF_STRUCT, sizeof(int));
    if (!temp)
    {
        result = MEMORY_ERROR;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            temp[i] = films[i].date;
        }
        int year_int = atoi(key);
        if (year_int == 0 || year_int <= 0)
        {
            free(temp);
            result = -2;
        }
        else
        {
            int index = int_binnary_search(year_int, temp, count);
            result = index;
            free(temp);
        }
    }
    return result;
}

int searching(description_of_films *films, char *key, char *field, int count)
{
    int result = SUCCESS;
    if (strcmp(field, "title") == 0)
    {
        result = searching_title(films, key, field, count);
    }
    else if (strcmp(field, "name") == 0)
    {
        result = searching_name(films, key, field, count);
    }
    else if (strcmp(field, "year") == 0)
    {
        result = searching_year(films, key, field, count);
    }
    else
    {
        result = SEARCHING_ERROR;
    }
    return result;
}
