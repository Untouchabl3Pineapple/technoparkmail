#include "utils.h"

void actionInfo(void) {
    printf("%s\n%s\n%s\n%s\n",
           "please enter action",
           "1 enter data client: ",
           "2 enter data transaction: ",
           "3 update base");
}

static void masterInfo(void) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "1 Number account: ",
           "2 Client name: ",
           "3 Surname: ",
           "4 Addres client: ",
           "5 Client Telnum: ",
           "6 Client indebtedness: ",
           "7 Client credit limit: ",
           "8 Client cash payments: ");
}

static void transactionInfo(void) {
    printf("%s\n%s\n",
           "1 Number account: ",
           "2 Client cash payments: ");
}

static void bufFree(FILE *const buf) {
    for (int c = getc(buf); c != '\n' && c != EOF; c = getc(buf)) {
    }
}

void masterWrite(FILE *const src, FILE *const dst, userData_t *const Client) {
    masterInfo();

    while (fscanf(src, "%12d%11s%11s%16s%20s%12lf%12lf%12lf", &Client->Number, \
                                                        Client->Name, \
                                                        Client->Surname, \
                                                        Client->addres, \
                                                        Client->TelNumber, \
                                                        &Client->indebtedness, \
                                                        &Client->credit_limit, \
                                                        &Client->cash_payments) == 8) {
        fprintf(dst, "%-12d%-11s%-11s%-16s%20s%12.2lf%12.2lf%12.2lf\n", Client->Number, \
                                                                          Client->Name, \
                                                                          Client->Surname, \
                                                                          Client->addres, \
                                                                          Client->TelNumber, \
                                                                          Client->indebtedness, \
                                                                          Client->credit_limit, \
                                                                          Client->cash_payments);

        masterInfo();
    }

    bufFree(src);
}

void transactionWrite(FILE *const src, FILE *const dst, userData_t *const transfer) {
    transactionInfo();

    while (fscanf(src, "%d%lf", &transfer->Number, &transfer->cash_payments) == 2) {
        fprintf(dst, "%-3d%-6.2f\n", transfer->Number, transfer->cash_payments);

        transactionInfo();
    }

    bufFree(src);
}

void blackRecord(FILE *const ofPTR, FILE *const ofPTR_2, FILE *const blackrecord, \
                 userData_t *const client_data, userData_t *const transfer) {
    while (fscanf(ofPTR, "%12d%11s%11s%16s%20s%12lf%12lf%12lf", &client_data->Number, \
                                                                client_data->Name, \
                                                                client_data->Surname, \
                                                                client_data->addres, \
                                                                client_data->TelNumber, \
                                                                &client_data->indebtedness, \
                                                                &client_data->credit_limit, \
                                                                &client_data->cash_payments) == 8) {
        while (fscanf(ofPTR_2, "%d %lf", &transfer->Number, &transfer->cash_payments) == 2) {
            if (client_data->Number == transfer->Number && transfer->cash_payments != 0) {
                client_data->credit_limit += transfer->cash_payments;
            }
        }

        fprintf(blackrecord, "%-12d%-11s%-11s%-16s%20s%12.2lf%12.2lf%12.2lf\n", client_data->Number, \
                                                                                client_data->Name, \
                                                                                client_data->Surname, \
                                                                                client_data->addres, \
                                                                                client_data->TelNumber, \
                                                                                client_data->indebtedness, \
                                                                                client_data->credit_limit, \
                                                                                client_data->cash_payments);

        rewind(ofPTR_2);
    }
}
