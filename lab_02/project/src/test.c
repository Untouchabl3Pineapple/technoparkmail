#include "utils.h"

static int print_file_data(FILE *const stream) {
    if (!stream) {
        return ERR_PRINT_FILE;
    }

    rewind(stream);

    for (int chr; (chr = fgetc(stream)) != EOF;) {
        printf("%c", chr);
    }

    return OK;
}

static int test_results(FILE *const record, FILE *const transaction, FILE *const blackrecord) {
    if (!record || !transaction || !blackrecord) {
        return ERR_TEST_RESULTS;
    }

    printf("\n_____TEST_____\n");
    printf("\nSTART FILES:\n");
    print_file_data(record);
    print_file_data(transaction);

    printf("\nRESULT FILES:\n");
    print_file_data(record);
    print_file_data(transaction);
    print_file_data(blackrecord);

    return OK;
}

static int my_test(void) {
    userdata_t client, transfer;

    FILE *src_rec = fopen("project/data/record.dat", "r");
    if (!src_rec) {
        return ERR_MY_TEST;
    }

    FILE *src_trans = fopen("project/data/transaction.dat", "r");
    if (!src_trans) {
        fclose(src_rec);

        return ERR_MY_TEST;
    }

    FILE *dst_rec = fopen("record.dat", "w+");
    FILE *dst_trans = fopen("transaction.dat", "w+");
    FILE *dst_blackrec = fopen("blackrecord.dat", "w+");

    master_write(dst_rec, src_rec, &client);
    transaction_write(dst_trans, src_trans, &transfer);

    fclose(src_rec);
    fclose(src_trans);

    rewind(dst_rec);
    rewind(dst_trans);

    black_record(dst_blackrec, dst_rec, dst_trans, &client, &transfer);

    test_results(dst_rec, dst_trans, dst_blackrec);

    fclose(dst_rec);
    fclose(dst_trans);
    fclose(dst_blackrec);

    return OK;
}

int main(void) {
    if (my_test() != OK) {
        return ERR_MY_TEST;
    }

    return OK;
}
