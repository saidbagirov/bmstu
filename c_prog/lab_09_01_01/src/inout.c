#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/inout.h"
#include "../inc/struct.h"

void first_init(description_of_films *films)
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
}

int scanning(char *input_path, description_of_films *films, int *count)
{
    int result = SUCCESS;
    FILE *f;
    f = fopen(input_path, "r");
    if (f)
    {
        first_init(films);
        for (int i = 0; !feof(f); i++)
        {
            int flag_name = 0;
            int flag_author = 0;
            fgets(films[i].name, NAME_LEN + 2, f);
            (*count)++;
            if (*count <= ((MAX_COUNT_OF_STRUCT - 1) * 3))
            {
                for (int j = 0; films[i].name[j] != '\0'; j++)
                {
                    if (films[i].name[j] == '\n')
                    {
                        flag_name = 1;
                        films[i].name[j] = '\0';
                    }
                }
                if (flag_name != 0 && films[i].name[0] != '\0')
                {
                    fgets(films[i].author, AUTHOR_LEN + 2, f);
                    (*count)++;
                    for (int j = 0; films[i].author[j] != '\0'; j++)
                    {
                        if (films[i].author[j] == '\n')
                        {
                            flag_author = 1;
                            films[i].author[j] = '\0';
                        }
                    }
                    if (flag_author == 0 || films[i].author[0] == '\0' || films[i].date < 0 || fscanf(f, "%d\n", &films[i].date) != 1 || films[i].date <= 0)
                    {
                        result = ERROR;
                    }
                    (*count)++;
                }
                else
                {
                    result = ERROR;
                }
            }
            else
            {
                result = ERROR;
            }
        }
        *count /= 3;
        if (*count > MAX_COUNT_OF_STRUCT - 1)
        {
            result = ERROR;
        }
        fclose(f);
    }
    else
    {
        result = ERROR;
    }
    return result;
}

void output_all(description_of_films *films, int count)
{
    for (int i = 0; i < count; i++)
        output_one(&films[i]);
}

void output_one(description_of_films *films)
{
    printf("%s\n", films->name);
    printf("%s\n", films->author);
    printf("%d\n", films->date);
}
