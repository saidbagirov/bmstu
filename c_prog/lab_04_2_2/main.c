#include <stdio.h>
#include <string.h>
#include "my_functions.h"

int main()
{
    int yes_no[WORD_LEN];
    int words_counter1 = 0;
    int words_counter2 = 0;
    char words1[WORDS_COUNT][WORD_LEN];
    char words2[WORDS_COUNT][WORD_LEN];
    char str1[STR_LEN];
    char str2[STR_LEN];
    if (string_input(str1) == 1 || string_input(str2) == 1)
    {
        return 1;
    }
    if (str_split(str1, words1, &words_counter1) == 1 || str_split(str2, words2, &words_counter2) == 1)
    {
        return 1;
    }
    delete_repeats(words1, &words_counter1);
    for (int i = 0; i < words_counter1; i++)
    {
        for (int j = 0; j < words_counter2; j++)
        {
            if (strcmp(words1[i], words2[j]) == 0)
            {
                yes_no[i] = 1;
                break;
            }
            else if (j == (words_counter2 - 1))
            {
                yes_no[i] = 0;
            }
        }
    }    
    printf("Result:\n");
    for (int i = 0; i < words_counter1; i++)
    {
        if (yes_no[i] == 1 && i != words_counter1 - 1)
        {
            printf("%s yes\n", words1[i]);
        }
        else if (yes_no[i] == 0 && i != words_counter1 - 1)
        {
            printf("%s no\n", words1[i]);
        }
        else if (yes_no[i] == 1)
        {
            printf("%s yes", words1[i]);
        }
        else if (yes_no[i] == 0)
        {
            printf("%s no", words1[i]);
        }
    }
    return 0;
}