#ifndef __LIST_H_
#define __LIST_H_
#include <stdlib.h>
#include <stdint.h>



typedef struct node node_t;
typedef struct node
{
    void *data;
    node_t *next;
} node;

node *list_create();

void list_dispose(node *head);

node *find(node *head, const void *data, int (*comparator)(const void *, const void *));

int copy(node *head, node **copy);

node *sort(node *head, int (*comparator)(const void *, const void *));

void sorted_insert(node **head, node *element, int (*comparator)(const void *, const void *));

#endif