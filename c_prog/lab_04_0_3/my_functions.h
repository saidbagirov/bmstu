#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_
#define STR_LEN 257
#define WORD_LEN 17
int str_split(char str[STR_LEN], char words[WORD_LEN][WORD_LEN], int *words_counter);
int string_input(char str[STR_LEN]);
int new_words_array(char words[WORD_LEN][WORD_LEN], int *words_counter);
int make_reverse_array(char words[WORD_LEN][WORD_LEN], char reverse_words[WORD_LEN][WORD_LEN], int words_counter);
int make_str_from_array(char reverse_words[WORD_LEN][WORD_LEN], char str[STR_LEN], int words_counter);
#endif