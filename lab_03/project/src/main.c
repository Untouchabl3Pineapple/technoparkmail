#include "matrix.h"

int main(void) {
    Matrix *matrix = NULL;

    matrix = create_matrix_from_file("test.txt");

    printMatrix(matrix);

    free_matrix(matrix);

    return OK;
}
