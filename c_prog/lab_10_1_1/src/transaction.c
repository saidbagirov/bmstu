#include "../inc/transaction.h"
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>



transaction *transaction_create(double value, char sender_name[], char recepient_name[])
{
    transaction *result = malloc(sizeof(transaction));
    if (!result) 
        return NULL;

    result->timestamp = time(NULL);
    result->value = value;
    result->id = (result->timestamp << 32) | (uint64_t)rand();
    strcpy(result->sender_name, sender_name);
    strcpy(result->recepient_name, recepient_name);

    return result;
}

void transaction_dispose(transaction *t)
{
    free(t);
}

int transaction_fscan(FILE *file, transaction **t)
{
    transaction tt;
    int res = fscanf(file, "%"PRIu64" %lf %127s %127s %"PRIu64, &tt.timestamp, &tt.value, tt.sender_name, tt.recepient_name, &tt.id) != 5;
    
    if (!res)
    {
        *t = malloc(sizeof(transaction));
        if (!*t) 
            return 1;

        (*t)->timestamp = tt.timestamp;
        (*t)->value = tt.value;
        (*t)->id = tt.id;
        strcpy((*t)->sender_name, tt.sender_name);
        strcpy((*t)->recepient_name, tt.recepient_name);
    }
    return res;
}

int transaction_fprint(FILE *file, const transaction *t)
{
    return fprintf(file, "%"PRIu64" %lf %s %s %"PRIu64"\n", t->timestamp, t->value, t->sender_name, t->recepient_name, t->id) != 5;
}

int transaction_compare_timestamp(const void *l, const void *r)
{
    int result = 0;
    if (((transaction *)l)->timestamp < ((transaction *)r)->timestamp) 
        result -1;
    if (((transaction *)l)->timestamp > ((transaction *)r)->timestamp) 
        result = 1;
    return result;
}

int transaction_compare_value(const void *l, const void *r)
{
    int result = 0;
    if (((transaction *)l)->value < ((transaction *)r)->value) 
        result = -1;
    if (((transaction *)l)->value > ((transaction *)r)->value) 
        result = 1;
    return result;
}

int transaction_compare_sender(const void *l, const void *r)
{
    return strcmp(((transaction *)l)->sender_name, ((transaction *)r)->sender_name);
}

int transaction_compare_recepient(const void *l, const void *r)
{
    return strcmp(((transaction *)l)->sender_name, ((transaction *)r)->sender_name);
}

int transaction_compare_id(const void *l, const void *r)
{
    int result = 0;
    if (((transaction *)l)->id < ((transaction *)r)->id) 
        result = -1;
    if (((transaction *)l)->id > ((transaction *)r)->id) 
        result = 1;
    return result;
}