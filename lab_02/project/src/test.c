#include "utils.h"

static void testResults(void) {
    system("clear");

    system("echo");

    system("echo START FILES:");
    system("cat project/data/record.dat project/data/transaction.dat");

    system("echo");

    system("echo RESULTS:");
    system("cat record.dat transaction.dat blackrecord.dat");

    system("echo");
}

static void myTest(void) {
    FILE *src_rec = fopen("project/data/record.dat", "r");
    FILE *src_trans = fopen("project/data/transaction.dat", "r");

    FILE *dst_rec = fopen("record.dat", "w+");
    FILE *dst_trans = fopen("transaction.dat", "w+");
    FILE *dst_blackrec = fopen("blackrecord.dat", "w");

    userData_t client, transfer;

    masterWrite(src_rec, dst_rec, &client);
    transactionWrite(src_trans, dst_trans, &transfer);

    fclose(src_rec);
    fclose(src_trans);

    rewind(dst_rec);
    rewind(dst_trans);

    blackRecord(dst_rec, dst_trans, dst_blackrec, &client, &transfer);

    fclose(dst_rec);
    fclose(dst_trans);
    fclose(dst_blackrec);

    testResults();
}

int main(void) {
    myTest();

    return OK;
}
