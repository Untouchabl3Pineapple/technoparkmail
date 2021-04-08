#include "case.h"

int main(void) {
    int choice = 0;
    FILE *file_record = NULL, *file_transaction = NULL, *file_blackrecord = NULL;
    userdata_t client, transfer;

    action_info();

    while (scanf("%d", &choice) == 1) {
        switch (choice) {
            case FILL_RECORD_DATA: {
                get_record_data(file_record, stdin, &client);

                break;
            }
            case FILL_TRANSACTION_DATA: {
                get_transaction_data(file_transaction, stdin, &client);

                break;
            }
            case FILL_BLACKRECORD_DATA: {
                get_blackrecord_data(file_blackrecord, file_record, file_transaction, &client, &transfer);

                break;
            }
            default: {
                puts("Error command");
            }
        }

        action_info();
    }

    return OK;
}

