#include "utils.h"

int main(void) {
    int choice = 0;
    FILE *Ptr, *Ptr_2, *blackrecord;
    userData_t client_data, transfer;

    actionInfo();

    while (scanf("%d", &choice) == 1) {
        switch (choice) {
            case 1: {
                Ptr = fopen("record.dat", "r+");
                if (Ptr == NULL) {
                    puts("No access");
                } else {
                    masterWrite(stdin, Ptr, &client_data);
                    fclose(Ptr);
                }
                break;
            }
            case 2: {
                Ptr = fopen("transaction.dat", "r+");
                if (Ptr == NULL) {
                    puts("No access");
                } else {
                    transactionWrite(stdin, Ptr, &transfer);
                    fclose(Ptr);
                }
                break;
            }
            case 3: {
                Ptr = fopen("record.dat", "r");
                Ptr_2 = fopen("transaction.dat", "r");
                blackrecord = fopen("blackrecord.dat", "w");

                if (Ptr == NULL || Ptr_2 == NULL) {
                    puts("Exit");
                } else {
                    blackRecord(Ptr, Ptr_2, blackrecord, &client_data, &transfer);
                    fclose(Ptr);
                    fclose(Ptr_2);
                    fclose(blackrecord);
                }
                break;
            }
            default: {
                puts("Error");
            }
        }

        actionInfo();
    }

    return OK;
}

