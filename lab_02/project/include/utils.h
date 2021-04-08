#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#include "data_struct.h"
#include "ret_codes.h"

void action_info(void);

void master_write(FILE *const dst, FILE *const src, userdata_t *const client);
void transaction_write(FILE *const dst, FILE *const src, userdata_t *const transfer);
void black_record(FILE *const blackrecord, FILE *const record, FILE *const transaction, \
                  userdata_t *const client, userdata_t *const transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
