#ifndef PROJECT_INCLUDE_CASE_H_
#define PROJECT_INCLUDE_CASE_H_

#include <stdio.h>

#include "data_struct.h"
#include "ret_codes.h"
#include "utils.h"

enum cases {
    FILL_RECORD_DATA = 1,
    FILL_TRANSACTION_DATA,
    FILL_BLACKRECORD_DATA,
};

int get_record_data(FILE *dst, FILE *const src, userdata_t *const client);
int get_transaction_data(FILE *dst, FILE *const src, userdata_t *const transfer);
int get_blackrecord_data(FILE *blackrecord, FILE *record, FILE *transaction, \
                         userdata_t *const client, userdata_t *const transfer);

#endif  // PROJECT_INCLUDE_CASE_H_
