#include <stdio.h>
#include <string.h>
#include "../inc/list.h"
#include "../inc/error_codes.h"



int perform_val();
int perform_ddx();
int perform_sum();
int perform_dvd();

int main()
{    
    int result = SUCCESS;
    char action[6];
    if (scanf("%5s", action) != 1)
        result = ARGS_ERROR;
    else if (!strcmp(action, "val")) 
        result = perform_val();
    else if (!strcmp(action, "ddx")) 
        result = perform_ddx();
    else if (!strcmp(action, "sum"))
        return perform_sum();
    else if (!strcmp(action, "dvd"))
        result = perform_dvd();
    else 
        result = ARGS_ERROR;
    return result;
}

int perform_val()
{
    int result = SUCCESS;
    node *head = list_scan();
    if (head)
    {
        int a;
        if (scanf("%d", &a) == 1)
        {
            int sum = list_val(head, a);

            printf("%d\n", sum);
        }
        else
            result = ARGS_ERROR;

        list_dispose(head);
    }
    else
        result = ARGS_ERROR;
    return result;
}

int perform_ddx()
{
    int result = SUCCESS;
    node *head = list_scan();
    if (head)
    {
        node *dhead = list_ddx(head);
        list_print(dhead);
        printf("\n");
        
        list_dispose(dhead);
        list_dispose(head);
    }
    else
        result = ARGS_ERROR;

    return result;
}

int perform_sum()
{
    int result = SUCCESS;
    node *lhead = list_scan();
    if (lhead)
    {
        node *rhead = list_scan();
        if (rhead)
        {
            node *head = list_sum(lhead, rhead);

            list_print(head);
            printf("\n");

            list_dispose(head);
            list_dispose(rhead);
        }
        else
            result = ARGS_ERROR;

        list_dispose(lhead);
    }
    else 
        result = ARGS_ERROR;

    return result;
}

int perform_dvd()
{
    int result = SUCCESS;
    
    node *head = list_scan_crutch();
    if (head)
    {
        node *lhead, *rhead;
        list_dvd(head, &lhead, &rhead);

        list_print(lhead);
        printf("\n");
        list_print(rhead);
        printf("\n");

        list_dispose(lhead);
        list_dispose(rhead);
        list_dispose(head);
    }
    else
        result = ARGS_ERROR;
    return result;
}