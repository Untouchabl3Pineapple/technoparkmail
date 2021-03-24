#include "matrix.h"

int main(void) {
    Matrix *matrix, *addit_matrix, *matrix_result;
    size_t rows, columns;
    double val;

    /*
        Test 1: Init/Out/release operations
    */

    system("echo Test 1: Init/release operations");

    matrix = create_matrix_from_file("project/data/test.txt");

    system("echo MATRIX:");
    my_print_matrix(matrix);

    free_matrix(matrix);

    system("echo Done");

    /*
        Test 2: Creating and deleting a matrix
    */

    system("echo Test 2: Creating and deleting a matrix");

    matrix = create_matrix_from_file("project/data/test.txt");

    get_rows(matrix, &rows);
    get_cols(matrix, &columns);

    get_elem(matrix, 0, 0, &val);
    set_elem(matrix, 0, 0, 100);

    printf("ROWS: %zu, COLUMNS: %zu\n", rows, columns);
    printf("GET_ELEM_VAL: %lf, SET_ELEM_VAL: %lf\n", val, matrix->data[0][0]);

    free_matrix(matrix);

    system("echo Done");

    /*
        Test 3: Math operations
    */

    system("echo Test 3: Math operations");

    // _____________________________________________________________________

    val = 10.;

    matrix = create_matrix_from_file("project/data/test.txt");

    system("echo MUL_SCALAR BEFORE:");
    my_print_matrix(matrix);
    matrix_result = mul_scalar(matrix, val);
    system("echo MUL_SCALAR AFTER:");
    my_print_matrix(matrix_result);

    free_matrix(matrix);
    free_matrix(matrix_result);

    // _____________________________________________________________________

    matrix = create_matrix_from_file("project/data/test.txt");

    system("echo TRANSP BEFORE:");
    my_print_matrix(matrix);
    matrix_result = transp(matrix);
    system("echo TRANSP AFTER:");
    my_print_matrix(matrix_result);

    free_matrix(matrix);
    free_matrix(matrix_result);

    // _____________________________________________________________________

    matrix = create_matrix_from_file("project/data/test.txt");

    system("echo TRANSP BEFORE:");
    my_print_matrix(matrix);
    matrix_result = transp(matrix);
    system("echo TRANSP AFTER:");
    my_print_matrix(matrix_result);

    free_matrix(matrix);
    free_matrix(matrix_result);

    // _____________________________________________________________________

    matrix = create_matrix_from_file("project/data/test.txt");
    addit_matrix = create_matrix_from_file("project/data/test.txt");

    system("echo SUM FIRST MATRIX:");
    my_print_matrix(matrix);
    system("echo SUM SECOND MATRIX:");
    my_print_matrix(addit_matrix);
    matrix_result = sum(matrix, addit_matrix);
    system("echo SUM RESULT MATRIX:");
    my_print_matrix(matrix_result);

    free_matrix(matrix);
    free_matrix(addit_matrix);
    free_matrix(matrix_result);

    // _____________________________________________________________________

    matrix = create_matrix_from_file("project/data/test.txt");
    addit_matrix = create_matrix_from_file("project/data/test.txt");

    system("echo SUB FIRST MATRIX:");
    my_print_matrix(matrix);
    system("echo SUB SECOND MATRIX:");
    my_print_matrix(addit_matrix);
    matrix_result = sub(matrix, addit_matrix);
    system("echo SUB RESULT MATRIX:");
    my_print_matrix(matrix_result);

    free_matrix(matrix);
    free_matrix(addit_matrix);
    free_matrix(matrix_result);

    // _____________________________________________________________________

    matrix = create_matrix_from_file("project/data/test.txt");
    addit_matrix = create_matrix_from_file("project/data/test.txt");

    system("echo MUL FIRST MATRIX:");
    my_print_matrix(matrix);
    system("echo MUL SECOND MATRIX:");
    my_print_matrix(addit_matrix);
    matrix_result = mul(matrix, addit_matrix);
    system("echo MUL RESULT MATRIX:");
    my_print_matrix(matrix_result);

    free_matrix(matrix);
    free_matrix(addit_matrix);
    free_matrix(matrix_result);

    // _____________________________________________________________________

    system("echo Done");

    /*
        Test 4: Extra operations
    */

    /*
        Gone to save the world :)

        P.S. Finish it for me :3 ples
    */

    system("echo Test 4: Extra operations");

    val = 228.;

    det(matrix, &val);
    adj(matrix);
    inv(matrix);

    system("echo Done");

    return OK;
}
