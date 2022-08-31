#include <stdio.h>
#include <string.h>
#include "my_functions.h"
int main()
{
    char new_str[STR_LEN];
    char str[STR_LEN];
    int words_counter;
    char words[WORD_LEN][WORD_LEN];
    char reverse_words[WORD_LEN][WORD_LEN];
    if (string_input(str) == 1)
    {
        return 1;
    }
    if (str_split(str, words, &words_counter) == 1)
    {
        return 1;
    }
    new_words_array(words, &words_counter);
    make_reverse_array(words, reverse_words, words_counter);
    make_str_from_array(reverse_words, new_str, words_counter);
    printf("Result: %s\n", new_str); 
    return 0;
}