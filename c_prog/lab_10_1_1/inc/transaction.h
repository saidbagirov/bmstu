#ifndef __TRANSACTION_H_
#define __TRANSACTION_H_

#include <stdint.h>
#include <stdio.h>



typedef struct transaction 
{
    uint64_t timestamp;
    double value;
    char sender_name[128];
    char recepient_name[128];
    uint64_t id;
} transaction;


transaction *transaction_create(double value, char sender_name[], char recepient_name[]);

void transaction_dispose(transaction *t);

int transaction_fscan(FILE* file, transaction **t);

int transaction_fprint(FILE* file, const transaction *t);

int transaction_compare_timestamp(const void *l, const void *r);

int transaction_compare_value(const void *l, const void *r);

int transaction_compare_sender(const void *l, const void *r);

int transaction_compare_recepient(const void *l, const void *r);

int transaction_compare_id(const void *l, const void *r);

#endif