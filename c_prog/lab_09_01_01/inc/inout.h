#include "error_codes.h"
#include "struct.h"
#ifndef __INOUT_H__
#define __INOUT_H__
void first_init(description_of_films *films);
int scanning(char *input_path, description_of_films *films, int *count);
void output_one(description_of_films *films);
void output_all(description_of_films *films, int count);
#endif
