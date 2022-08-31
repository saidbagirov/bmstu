#include "../inc/list.h"
#include "../inc/error_codes.h"
#include <stdio.h>
#include <string.h>



node *list_create()
{
    node *result = malloc(sizeof(node));
    if (result)
    {
        result->data = NULL;
        result->next = NULL;
    }
    return result;
}

void list_dispose(node *head)
{
    if (head)
    {
        node *next = head->next;
        while (next)
        {
            free(head);
            head = next;
            next = head->next;
        }
        free(head);
    }
}

node *find(node *head, const void *data, int (*comparator)(const void *, const void *))
{
    while (head && comparator(data, head->data)) 
        head = head->next;
    return head;
}

int copy(node *head, node **copy)
{
    int result = SUCCESS;
    if (!head) 
    {
        *copy = NULL;
        result = MEMORY_ERROR;
    }
    else
    {
        *copy = malloc(sizeof(node));
        if (*copy)
        {
            node *copy_head = (*copy);

            do
            {
                copy_head->data = head->data;
                if (head->next)
                {
                    copy_head->next = malloc(sizeof(node));
                            
                    if (!copy_head->next)
                    {
                        list_dispose(*copy);
                        *copy = NULL;
                        result = MEMORY_ERROR;
                        break;
                    }
                    copy_head = copy_head->next;
                }
                else
                    copy_head->next = NULL;

                head = head->next;
            } while (head);
        }
        else
            result = MEMORY_ERROR;
    }
    return result;
}

node *sort(node *head, int (*comparator)(const void *, const void *))
{
    node *res = NULL;
    while (head)
    {
        node *tmp = head;
        head = head->next; 
        sorted_insert(&res, tmp, comparator);
    }

    return res;
}

void sorted_insert(node **head, node *element, int (*comparator)(const void *, const void *))
{
    if (!*head)
    {
        *head = element;
        element->next = NULL;
    }
    else if (element) 
    {
        node *cur = *head;

        if (comparator(element->data, cur->data) <= 0)
        {
            element->next = *head;
            *head = element;
        }
        else
        {
            while (cur->next && comparator(element->data, cur->next->data) > 0)
                cur = cur->next;
            element->next = cur->next;
            cur->next = element;
        }
    }
}


