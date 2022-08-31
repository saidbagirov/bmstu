#include "../inc/list.h"
#include <stdio.h>
#include <string.h>



node *list_create()
{
    node *result = malloc(sizeof(node));
    if (result)
    {
        result->mul = 0;
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

node *list_scan()
{
    int count;
    node *head = NULL;
    if (scanf("%d", &count) == 1 && count >= 0)
    {
        node *cur = NULL;
        while (count--)
        {
            int mul;
            if (!scanf("%d", &mul))
            {
                list_dispose(head);
                head = NULL;
                break;
            }

            cur = list_create();
            cur->mul = mul;
            cur->next = head;
            head = cur;
        } 
    }
    return head;
}

node *list_scan_crutch()
{
    int count;
    node *head = NULL;
    if (scanf("%d", &count) == 1 && count >= 0)
    {
        count++;

        node *cur = NULL;
        while (count--)
        {
            int mul;
            if (!scanf("%d", &mul))
            {
                list_dispose(head);
                head = NULL;
                break;
            }

            cur = list_create();
            cur->mul = mul;
            cur->next = head;
            head = cur;
        } 
    }
    return head;
}

void list_print(const node *head)
{
    while (head)
    {
        printf("%d ", head->mul);
        head = head->next;
    }
    printf("L");
}

int list_val(const node *head, int a)
{
    const node *cur = head;
    int pow = 1;
    int sum = 0;
    while (cur)
    {
        sum += pow * cur->mul;
        cur = cur->next;
        pow *= a;
    }
    return sum;
}

node *list_ddx(const node *head)
{
    node *res = NULL;
    if (head)
    {
        node *cur = head->next;
        int pow = 1;
        while (cur)
        {
            node *tmp = list_create();
            tmp->mul = cur->mul * pow;
            tmp->next = res;
            res = tmp;

            cur = cur->next;
            pow++;
        }
    }
    return res;
}

node *list_sum(const node *lhead, const node *rhead)
{
    const node *lcur = lhead;
    const node *rcur = rhead;
    node *head = NULL;

    while (lcur || rcur)
    {
        node *tmp = list_create();
        tmp->next = head;
        head = tmp;
        if (lcur && rcur)
        {
            tmp->mul = lcur->mul + rcur->mul;
            lcur = lcur->next;
            rcur = rcur->next;
        }
        else if (lcur)
        {
            tmp->mul = lcur->mul;
            lcur = lcur->next;
        }
        else 
        {
            tmp->mul = rcur->mul;
            rcur = rcur->next;
        }
    }

    return head;
}

void list_dvd(const node *head, node **lhead, node **rhead)
{
    *lhead = NULL;
    *rhead = NULL;

    const node *cur = head;
    int pow = 0;
    while (cur)
    {
        node *tmp = list_create();
        tmp->mul = cur->mul;
        if (pow % 2 == 0)
        {
            tmp->next = *lhead;
            *lhead = tmp;
        }
        else
        {
            tmp->next = *rhead;
            *rhead = tmp;
        }
        pow++;
        
        cur = cur->next;
    }
}