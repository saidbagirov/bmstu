#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



int fgetfilm(FILE *f, description_of_films *film)
{
    int result = 0;
    int flag_name = 0;
    int flag_author = 0;
    fgets(film->name, NAME_LEN + 2, f);

    for (int j = 0; film->name[j] != '\0'; j++)
    {
        if (film->name[j] == '\n')
        {
            flag_name = 1;
            film->name[j] = '\0';
        }
    }
    if (flag_name == 0)
        result = 1;
    else
    {
        if (film->name[0] == '\0')
            result = 1;
        else
        {
            fgets(film->author, AUTHOR_LEN + 2, f);
            for (int j = 0; film->author[j] != '\0'; j++)
            {
                if (film->author[j] == '\n')
                {
                    flag_author = 1;
                    film->author[j] = '\0';
                }
            }
            if (flag_author == 0)
                result = 1;
            else
            {
                if (film->author[0] == '\0')
                    result = 1;
                else
                {
                    if (fscanf(f, "%d\n", &film->date) != 1)
                        result = 1;
                    else
                    {
                        if (film->date < 0)
                            result = 1;
                    }
                }
            }
        }
    }
    return result;
}

int scanning(char *input_path, description_of_films films[MAX_COUNT_OF_STRUCT], int *count)
{
    int result = 0;
    FILE *f;
    f = fopen(input_path, "r");
    if (!f)
        result = 1;
    else
    {
        for (int i = 0; i < MAX_COUNT_OF_STRUCT; i++)
        {
            for (int j = 0; j < NAME_LEN; j++)
            {
                films[i].name[j] = '\0';
            }
            for (int j = 0; j < AUTHOR_LEN; j++)
            {
                films[i].author[j] = '\0';
            }
            films[i].date = 0;
        }
        for (int i = 0; !feof(f); i++)
        {
            (*count)++;
            if (*count > ((MAX_COUNT_OF_STRUCT - 1) * 3))
            {
                result = 1;
                break;
            }
            if (fgetfilm(f, films + i))
            {
                result = 1;
                break;
            }
        }
        *count /= 3;
        if (*count > MAX_COUNT_OF_STRUCT - 1)
        {
            result = 1;
        }
        fclose(f);
    }
    return result;
}

int charbinnarysearch(char a[NAME_LEN], char temp[MAX_COUNT_OF_STRUCT][NAME_LEN], int count)
{
    int result = SEARCHING_NOT_FOUND;
    int low, high, middle;
    low = 0;
    high = count - 1;
    while (low <= high)
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
            break;
        }
    }
    return result;
}

void swap(description_of_films *f, description_of_films *s)
{
    description_of_films temp = *f;
    *f = *s;
    *s = temp;
}
int sorting(description_of_films films[MAX_COUNT_OF_STRUCT], char *field, int count)
{
    int result = 0;
    if (strcmp(field, "title") == 0)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 1; j < count; j++)
            {
                if (strcmp(films[j].name, films[j - 1].name) < 0)
                {
                    swap(films + j, films + j - 1);
                }
            }
        }
    }
    else if (strcmp(field, "name") == 0)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 1; j < count; j++)
            {
                if (strcmp(films[j].author, films[j - 1].author) < 0)
                {
                    swap(films + j, films + j - 1);
                }
            }
        }
    }
    else if (strcmp(field, "year") == 0)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 1; j < count; j++)
            {
                if (films[j].date < films[j - 1].date)
                {
                    swap(films + j, films + j - 1);
                }
            }
        }
    }
    else 
    {
        result = 1;
    }
    return result;
}

int output_all(description_of_films films[MAX_COUNT_OF_STRUCT], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", films[i].name);
        printf("%s\n", films[i].author);
        printf("%d\n", films[i].date);
    }
    return 0;
}

int output_one(description_of_films films[MAX_COUNT_OF_STRUCT], int count, int index)
{
    printf("%s\n", films[index].name);
    printf("%s\n", films[index].author);
    printf("%d\n", films[index].date);
    return 0;
}

int intbinnarysearch(int a, int temp[MAX_COUNT_OF_STRUCT], int count)
{
    int result = SEARCHING_NOT_FOUND;
    int low, high, middle;
    low = 0;
    high = count - 1;
    while (low <= high)
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
            break;
        }
    }
    return result;
}

int searching(description_of_films films[MAX_COUNT_OF_STRUCT], char *key, char *field, int count)
{
    int result = 0;
    if (strcmp(field, "title") == 0)
    {
        char temp[MAX_COUNT_OF_STRUCT][NAME_LEN];
        for (int i = 0; i < count; i++)
        {
            strcpy(temp[i], films[i].name);
        }
        int index = charbinnarysearch(key, temp, count);
        result = index;
    }
    else if (strcmp(field, "name") == 0)
    {
        char temp[MAX_COUNT_OF_STRUCT][AUTHOR_LEN];
        for (int i = 0; i < count; i++)
        {
            strcpy(temp[i], films[i].author);
        }
        int index = charbinnarysearch(key, temp, count);
        result = index;
    }
    else if (strcmp(field, "year") == 0)
    {
        int temp[MAX_COUNT_OF_STRUCT];
        for (int i = 0; i < count; i++)
        {
            temp[i] = films[i].date;
        }
        int year_int = atoi(key);
        if (year_int == 0 || year_int <= 0)
        {
            result = SEARCHING_ERROR;
        }
        else
        {
            int index = intbinnarysearch(year_int, temp, count);
            result = index;
        }
    }
    else
    {
        result = SEARCHING_ERROR;
    }
    return result;
}