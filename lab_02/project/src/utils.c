#include "utils.h"

void action_info(void) {
    printf("%s\n%s\n%s\n%s\n",
           "please enter action",
           "1 enter data client: ",
           "2 enter data transaction: ",
           "3 update base");
}

static void master_info(void) {
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

static void transaction_info(void) {
    printf("%s\n%s\n",
           "1 Number account: ",
           "2 Client cash payments: ");
}

static void buf_free(FILE *const buf) {
    for (int c = getc(buf); c != '\n' && c != EOF; c = getc(buf)) {
    }
}

void master_write(FILE *const dst, FILE *const src, userdata_t *const client) {
    master_info();

    while (fscanf(src, "%12d%11s%11s%16s%20s%12lf%12lf%12lf", &client->number, \
                                                        client->name, \
                                                        client->surname, \
                                                        client->addres, \
                                                        client->telnumber, \
                                                        &client->indebtedness, \
                                                        &client->credit_limit, \
                                                        &client->cash_payments) == 8) {
        fprintf(dst, "%-12d%-11s%-11s%-16s%20s%12.2lf%12.2lf%12.2lf\n", client->number, \
                                                                          client->name, \
                                                                          client->surname, \
                                                                          client->addres, \
                                                                          client->telnumber, \
                                                                          client->indebtedness, \
                                                                          client->credit_limit, \
                                                                          client->cash_payments);

        master_info();
    }

    buf_free(src);
}

void transaction_write(FILE *const dst, FILE *const src, userdata_t *const transfer) {
    transaction_info();

    while (fscanf(src, "%d%lf", &transfer->number, &transfer->cash_payments) == 2) {
        fprintf(dst, "%-3d%-6.2f\n", transfer->number, transfer->cash_payments);

        transaction_info();
    }

    buf_free(src);
}

void black_record(FILE *const blackrecord, FILE *const record, FILE *const transaction, \
                  userdata_t *const client, userdata_t *const transfer) {
    while (fscanf(record, "%12d%11s%11s%16s%20s%12lf%12lf%12lf", &client->number, \
                                                                client->name, \
                                                                client->surname, \
                                                                client->addres, \
                                                                client->telnumber, \
                                                                &client->indebtedness, \
                                                                &client->credit_limit, \
                                                                &client->cash_payments) == 8) {
        while (fscanf(transaction, "%d %lf", &transfer->number, &transfer->cash_payments) == 2) {
            if (client->number == transfer->number && transfer->cash_payments != 0) {
                client->credit_limit += transfer->cash_payments;
            }
        }

        fprintf(blackrecord, "%-12d%-11s%-11s%-16s%20s%12.2lf%12.2lf%12.2lf\n", client->number, \
                                                                                client->name, \
                                                                                client->surname, \
                                                                                client->addres, \
                                                                                client->telnumber, \
                                                                                client->indebtedness, \
                                                                                client->credit_limit, \
                                                                                client->cash_payments);

        rewind(transaction);
    }
}
