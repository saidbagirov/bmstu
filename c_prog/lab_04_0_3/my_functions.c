#include <stdio.h>
#include <string.h>
#include "my_functions.h"

int str_split(char str[STR_LEN], char words[WORD_LEN][WORD_LEN], int *words_counter)
{
    int i = 0;
    char *str_tmp = strtok(str, " ;,.:-.!?");
    str_tmp[strlen(str_tmp)] = '\0';
    do
    {
        if (strlen(str_tmp) > 16)
        {
            return 1;
        }
        strncpy(words[i], str_tmp, WORD_LEN);
        i++;
        str_tmp = strtok(NULL, " ;,.:-.!?");
    }while (str_tmp);
    *words_counter = i;
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
    if (str[0] == '\0')
    {
        return 1;
    }
    return 0; 
}

int delete_repeats_of_first_letter(char word[WORD_LEN])
{
    int i = 1;
    while (1)
    {
        if (word[i] == word[0])
        {
            for (int j = i; j < strlen(word); j++)
            {
                word[j] = word[j + 1];
            }
            i--;
        }
        if (word[i + 1] == '\0')
        {
            break;
        }
        i++;
    }
    return 0;
}
int new_words_array(char words[WORD_LEN][WORD_LEN], int *words_counter)
{
    for (int i = 0; i < *words_counter; i++)
    {
        if (strcmp(words[i], words[*words_counter - 1]) == 0)
        {
            for (int j = i; j < *words_counter - 1; j++)
            {
                //int len = strlen(words[j + 1]) + 1;
                strncpy(words[j], words[j + 1], WORD_LEN);
            }
            *words_counter -= 1;
            i--;
        }
    } 
    for (int i = 0; i < *words_counter; i++)
    {
        delete_repeats_of_first_letter(words[i]);
    }
    return 0;
}
int make_reverse_array(char words[WORD_LEN][WORD_LEN], char reverse_words[WORD_LEN][WORD_LEN], int words_counter)
{
    int j = 0;
    for (int i = words_counter - 1; i >= 0; i--)
    {
        strncpy(reverse_words[j], words[i], WORD_LEN);
        j++;
    }
    return 0;
}
int make_str_from_array(char words[WORD_LEN][WORD_LEN], char str[STR_LEN], int words_counter)
{
    int i = 0;
    int j = 0;
    int l = 0;
    while (1)
    {
        if (words[i][j] != '\0')
        {
            str[l] = words[i][j];
            j++;
            l++;
        }
        else if (i == words_counter - 1)
        {
            str[l] = '\0';
            break;
        }
        else
        {
            str[l] = ' ';
            l++;
            j = 0;
            i++;
        }
    }
    return 0;
}