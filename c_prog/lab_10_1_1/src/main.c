#include <stdio.h>
#include <string.h>
#include "../inc/transaction.h"
#include "../inc/list.h"
#include "../inc/error_codes.h"



int choose_sort(node **head, char s);
int transactions_read(node **head, const char *in_file);

int main(int argc, char **argv)
{    
    int result = SUCCESS;
    const char *in_file = NULL;
    const char *out_file = NULL;
    char s = 0;
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-i"))
        {
            if (i + 1 < argc) 
                in_file = argv[++i];
        }
        else if (!strcmp(argv[i], "-o"))
        {
            if (i + 1 < argc) 
                out_file = argv[++i];
        }
        else if (!strcmp(argv[i], "-s"))
        {
            if (i + 1 < argc) 
                s = argv[++i][0];
        }
    }
    if (in_file && out_file) 
    {
        node *head = NULL;
        node **cur = &head;

        if (!(result = transactions_read(&head, in_file))) 
        {
            if (!(result = choose_sort(&head, s)))
            {
                printf("%d\n", s);

                FILE *fout = fopen(out_file, "w");
                if (fout)
                {
                    cur = &head;
                    while (*cur)
                    {
                        transaction_fprint(fout, (*cur)->data);
                        cur = &(*cur)->next;
                    }

                    fclose(fout);
                }
                else
                    result = FILE_ERROR;
            }

            cur = &head;
            while (*cur)
            {
                transaction_dispose((*cur)->data);
                cur = &(*cur)->next;
            }
            list_dispose(head);
        }
    }
    else
        result = ARGS_ERROR;

    return result;
}

int choose_sort(node **head, char s)
{
    int result = 0;
    switch (s)
    {
        case 't': 
            *head = sort(*head, &transaction_compare_timestamp); 
            break;
        case 'v': 
            *head = sort(*head, &transaction_compare_value); 
            break;
        case 's':   
            *head = sort(*head, &transaction_compare_sender); 
            break;
        case 'r': 
            *head = sort(*head, &transaction_compare_recepient); 
            break;
        case 'i': 
            *head = sort(*head, &transaction_compare_id); 
            break;
        default:
            result = ARGS_ERROR;
    }
    return result;
}

int transactions_read(node **head, const char *in_file)
{
    int result = SUCCESS;
    node **cur = head;
    FILE *fin = fopen(in_file, "r");
    if (fin)
    {
        transaction *t;
        while (!transaction_fscan(fin, &t))
        {
            *cur = list_create();
            if (!cur)
            {
                list_dispose(*head);
                result = MEMORY_ERROR;
                break;
            }
            (*cur)->data = t;
            cur = &(*cur)->next;
        }
        fclose(fin);
    }
    else
        result = FILE_ERROR;
    return result;
}