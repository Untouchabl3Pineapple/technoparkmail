#ifndef PROJECT_INCLUDE_DATA_STRUCT_H_
#define PROJECT_INCLUDE_DATA_STRUCT_H_

typedef struct {
    int number;
    char name[20];
    char surname[20];
    char addres[30];
    char telnumber[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} userdata_t;

#endif  // PROJECT_INCLUDE_DATA_STRUCT_H_
