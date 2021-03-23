#include "matrix.h"

int main(void) {
    Matrix *matrix, *matrix_res;

    /*
        Test 1: Init/release operations
    */

    system("echo Test 1: Init/release operations");

    matrix = NULL;

    matrix = create_matrix_from_file("project/data/test.txt");

    free_matrix(matrix);

    system("echo Done");

    /*
        Test 2: Creating and deleting a matrix
    */

    system("echo Test 2: Creating and deleting a matrix");
   
    matrix = NULL;
    size_t rows, columns;
    double val;

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

    




    return OK;
}
