#ifndef __SORT_FUNC_H__
#define __SORT_FUNC_H__

#include <stdio.h>
int comp(const void *i, const void *j);
void mysort(void *array, size_t count, size_t size, int (*comp)(const void *i, const void *j));

#endif