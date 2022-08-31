#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_
#define STR_LEN 257
#define WORD_LEN 17
#define WORDS_COUNT 129
int str_split(char a[STR_LEN], char words[WORD_LEN][WORD_LEN], int *words_counter);
int string_input(char str[STR_LEN]);
int delete_repeats(char words[WORD_LEN][WORD_LEN], int *words_counter);
#endif