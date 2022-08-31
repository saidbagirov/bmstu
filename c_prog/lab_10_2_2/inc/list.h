#ifndef __LIST_H_
#define __LIST_H_
#include <stdlib.h>
#include <stdint.h>



typedef struct node node_t;
typedef struct node
{
    int mul;
    node_t *next;
} node;

node *list_create();

void list_dispose(node *head);

node *list_scan();

node *list_scan_crutch();

void list_print(const node *head);

int list_val(const node *head, int a);

node *list_ddx(const node *head);

node *list_sum(const node *lhead, const node *rhead);

void list_dvd(const node *head, node **lhead, node **rhead);

#endif