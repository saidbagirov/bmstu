#include <stdio.h>
#include <string.h>
#include "my_functions.h"
int str_split(char str[STR_LEN], char words[WORDS_COUNT][WORD_LEN], int *words_counter)
{
    char str_new[STR_LEN];
    int j = 0;
    int i = 0;
    while (1)
    {
        if (str[i] == '\0')
        {
            str_new[j] = '\0';
            break;
        }
        if (str[i] != ',' && str[i] != ';' && str[i] != ':' && str[i] != '-' 
            && str[i] != '.' && str[i] != '!' && str[i] != '?' && str[i] != ' ')
        {
            str_new[j] = str[i];
            j++;
            if (str[i + 1] == '\0')
            {
                str_new[j] = '\0';
            }
        }
        else if (j != 0)
        {
            if (str_new[j - 1] == ' ')
            {
                if (str[i + 1] == '\0')
                    str_new[j - 1] = '\0';
            }
            else
            {
                str_new[j] = ' ';
                if (str[i + 1] == '\0')
                    str_new[j] = '\0';
                j++;
            }  
        }
        i++;
    }
    int inew = 0;
    int jnew = 0;
    i = 0;
    while (1)
    {
        if (str_new[i] != ' ' && str_new[i] != '\0')
        {
            words[inew][jnew] = str_new[i];
            jnew++;
            if (jnew == 16)
            {
                words[inew][jnew - 1] = '\0';
                return 1;
            }
        }
        else if (str_new[i] == '\0')
        {
            words[inew][jnew] = '\0';
            *words_counter += 1;
            break;
        }
        else
        {
            words[inew][jnew] = '\0';
            inew++;
            jnew = 0;
            *words_counter += 1;
        }
        i++;
    }
    return 0;
}
int string_input(char str[STR_LEN])
{
    int i = 0;
    while (1)
    {
        str[i] = getchar();
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;
        if (i == STR_LEN - 1)
        {
            str[i] = '\0';
            return 1;
        }
    }
    if (str[0] == '\n')
    {
        str[0] = '\0';
        return 1;
    }
    return 0; 
}

int delete_repeats(char words[WORDS_COUNT][WORD_LEN], int *words_counter)
{
    for (int i = 0; i < *words_counter; i++)
    {
        for (int j = 0; j < *words_counter; j++)
        {
            if (i != j && strcmp(words[i], words[j]) == 0)
            {
                if (j > i)
                {
                    for (int k = j; k < *words_counter - 1; k++)
                    {
                        strncpy(words[k], words[k + 1], WORD_LEN);
                    }
                }
                else
                {
                    for (int k = i; k < *words_counter - 1; k++)
                    {
                        strncpy(words[k], words[k + 1], WORD_LEN);
                    }
                }
                *words_counter -= 1;  
                words[*words_counter][0] = '\0';
            }
        }
    }
    return 0;
}