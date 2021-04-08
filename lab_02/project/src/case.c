#include "case.h"

int get_record_data(FILE *dst, FILE *const src, userdata_t *const client) {
    int rc = OK;

    dst = fopen("record.dat", "r+");

    if (!dst) {
        rc = ERR_GET_RECORD_DATA;
        puts("No access");
    } else {
        master_write(dst, src, client);
        fclose(dst);
    }

    return rc;
}

int get_transaction_data(FILE *dst, FILE *const src, userdata_t *const transfer) {
    int rc = OK;

    dst = fopen("transaction.dat", "r+");

    if (!dst) {
        rc = ERR_GET_TRANSACTION_DATA;
        puts("No access");
    } else {
        transaction_write(dst, src, transfer);
        fclose(dst);
    }

    return rc;
}

int get_blackrecord_data(FILE *blackrecord, FILE *record, FILE *transaction, \
                         userdata_t *const client, userdata_t *const transfer) {
    int rc = OK;

    blackrecord = NULL;

    record = fopen("record.dat", "r");
    transaction = fopen("transaction.dat", "r");

    if (!record || !transaction) {
        rc = ERR_GET_BLACKRECORD_DATA;
        puts("No access");
    } else {
        blackrecord = fopen("blackrecord.dat", "w");
        black_record(blackrecord, record, transaction, client, transfer);
    }

    if (record != NULL) {
        fclose(record);
    }
    if (transaction != NULL) {
        fclose(transaction);
    }
    if (blackrecord != NULL) {
        fclose(blackrecord);
    }

    return rc;
}
