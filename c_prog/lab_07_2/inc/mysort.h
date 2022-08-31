#ifndef __MYSORT_H__
#define __MYSORT_H__
#include <stdlib.h>



typedef int (*comparer)(const void *a, const void *b);

void mysort(void *data, size_t num_elem, size_t size_elem, comparer cmp);

int cmp_fun(const void *l, const void *r);

#endif