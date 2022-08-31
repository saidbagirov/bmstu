#include "../inc/my_functions.h"
#include "../inc/error_codes.h"



int count_films(FILE *f)
{
    int count;
    for (count = 0; !feof(f); count++)
    {
        description_of_films t;
        int flag;

        if (fgets(t.name, NAME_LEN + 2, f) == NULL)
        {
            count = -1;
            break;
        }

        flag = 0;
        for (int j = 0; t.name[j] != '\0'; j++)
        {
            if (t.name[j] == '\n')
            {
                flag = 1;
                t.name[j] = '\0';
            }
        }
        if (flag == 0)
        {
            count = -1;
            break;
        }

        if (fgets(t.author, AUTHOR_LEN + 2, f) == NULL)
        {
            count = -1;
            break;
        }

        flag = 0;
        for (int j = 0; t.author[j] != '\0'; j++)
        {
            if (t.author[j] == '\n')
            {
                flag = 1;
                t.author[j] = '\0';
            }
        }
        if (flag == 0)
        {
            count = -1;
            break;
        }

        if (fscanf(f, "%d\n", &t.date) != 1)
        {
            count = -1;
            break;
        }

        if (t.date < 0) 
        {
            count = -1;
            break;
        }
        
        if (t.name[0] == '\0')
        {
            count = -1;
            break;
        }
        if (t.author[0] == '\0')
        {
            count = -1;
            break;
        }
    }
    return count;
}

int scanning(char *input_path, description_of_films **films, int *count)
{
    int result = SUCCESS;
    FILE *f;
    f = fopen(input_path, "r");
    if (f)
    {
        *count = count_films(f);
        if (*count >= 0)
        {
            fseek(f, 0, SEEK_SET);

            *films = malloc(*count * sizeof(description_of_films));
            if (films)
            {
                for (int i = 0; !feof(f); i++)
                {
                    fgets((*films)[i].name, NAME_LEN + 2, f);
                    fgets((*films)[i].author, AUTHOR_LEN + 2, f);
                    fscanf(f, "%d\n", &(*films)[i].date);
                    

                    for (int j = 0; (*films)[i].name[j] != '\0'; j++)
                        if ((*films)[i].name[j] == '\n')
                            (*films)[i].name[j] = '\0';
                    
                    for (int j = 0; (*films)[i].author[j] != '\0'; j++)
                        if ((*films)[i].author[j] == '\n')
                            (*films)[i].author[j] = '\0';
                }
            }
            else
                result = MEMORY_ERROR;
        }
        else 
            result = READ_ERROR;

        fclose(f);
    }
    else 
        result = FILE_ERROR;
    return result;
}

void swap(description_of_films *f1, description_of_films *f2) 
{
    description_of_films temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}

void sorting_title(description_of_films *films, int count)
{
    description_of_films temp;
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

void sorting_name(description_of_films *films, int count)
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

void sorting_year(description_of_films *films, int count)
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

int sorting(description_of_films *films, char *field, int count)
{
    int res = SUCCESS;
    if (strcmp(field, "title") == 0)
        sorting_title(films, count);
    else if (strcmp(field, "name") == 0)
        sorting_name(films, count);
    else if (strcmp(field, "year") == 0)
        sorting_year(films, count);
    else 
        res = ARGS_ERROR;
    return res;
}

int output_all(description_of_films *films, int count)
{
    for (int i = 0; i < count; i++)
        output_one(films, count, i);
    return 0;
}

int output_one(description_of_films *films, int count, int index)
{
    printf("%s\n", films[index].name);
    printf("%s\n", films[index].author);
    printf("%d\n", films[index].date);
    return 0;
}

int charbinnarysearch(char a[NAME_LEN], void *data, size_t offset, int count)
{
    int result = -1;
    int low, high, middle;
    low = 0;
    high = count - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (strcmp(a, (char *)data + middle * offset) < 0)
        {
            high = middle - 1;
        }
        else if (strcmp(a, (char *)data + middle * offset) > 0)
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

int intbinnarysearch(int a, void *data, size_t offset, int count)
{
    int result = -1;
    int low, high, middle;
    low = 0;
    high = count - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < *(int *)((char *)data + middle * offset))
        {
            high = middle - 1;
        }
        else if (a > *(int *)((char *)data + middle * offset))
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

int searching(description_of_films *films, char *key, char *field, int count)
{
    int index;
    if (strcmp(field, "title") == 0)
        index = charbinnarysearch(key, films->name, sizeof(description_of_films), count);
    else if (strcmp(field, "name") == 0)
        index = charbinnarysearch(key, films->author, sizeof(description_of_films), count);
    else if (strcmp(field, "year") == 0)
    {
        int year_int = atoi(key);
        if (year_int <= 0)
            index = -2;
        else
            index = intbinnarysearch(year_int, &films->date, sizeof(description_of_films), count);
    }
    else 
        index = -2;
    return index;
}