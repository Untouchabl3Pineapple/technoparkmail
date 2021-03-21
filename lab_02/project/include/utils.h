#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define OK          0

typedef struct {
    int Number;
    char Name[20];
    char Surname[20];
    char addres[30];
    char TelNumber[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} userData_t;

void actionInfo(void);

void masterWrite(FILE *const src, FILE *const dst, userData_t *const Client);
void transactionWrite(FILE *const src, FILE *const dst, userData_t *const transfer);
void blackRecord(FILE *const ofPTR, FILE *const ofPTR_2, FILE *const blackrecord, \
                 userData_t *const client_data, userData_t *const transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
