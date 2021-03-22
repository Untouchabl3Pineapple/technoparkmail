#include "matrix.h"

// _________________________Init/release operations_________________________

Matrix *create_matrix_from_file(const char* path_file) {
    FILE *f = fopen(path_file, "r");

    if (f == NULL) {
        return NULL;
    }

    Matrix *matrix = NULL;
    size_t rows, columns;

    if (fscanf(f, "%zd%zd", &rows, &columns) != 2) {
        return NULL;
    }
    if (rows < 1 || columns < 1) {
        return NULL;
    }

    if ((matrix = create_matrix(rows, columns)) == NULL) { 
        return NULL;
    }

    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->columns; j++) {
            if (fscanf(f, "%lf", &matrix->data[i][j]) != 1) {
                return NULL;
            }
        }
    }

    fclose(f);

    return matrix;
}

Matrix *create_matrix(size_t rows, size_t cols) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));

    matrix->rows = rows;
    matrix->columns = cols;

    matrix->data = (double **) malloc(matrix->rows * sizeof(double *));
    if (!matrix->data) {
        return NULL;
    }

    for (size_t i = 0; i < matrix->rows; i++) {
        matrix->data[i] = (double *) malloc(matrix->columns * sizeof(double));
        if (!matrix->data[i]) {
            return NULL;
        }
    }

    return matrix;
}

int free_matrix(Matrix* matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }

    free(matrix->data);
    
    return OK;
}

void printMatrix(Matrix* matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->columns; j++) {
            printf("%lf", matrix->data[i][j]);
        }
    }
}

// ____________________________Basic operations_____________________________

int get_rows(const Matrix* matrix, size_t* rows) {
    if (matrix == NULL) {
        return ERR_GET_ELEMENT;
    }

    *rows = matrix->rows;

    if (*rows < 1) {
        return ERR_ROWS_FILL;
    }

    return OK;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (matrix == NULL) {
        return ERR_GET_ELEMENT;
    }

    *cols = matrix->columns;

    if (*cols < 1) {
        return ERR_COLUMNS_FILL;
    }

    return OK;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (matrix == NULL) {
        return ERR_GET_ELEMENT;
    }

    if (row < 1 || row > matrix->rows) {
        return ERR_GET_ELEMENT;
    }
    if (col < 1 || col > matrix->columns) {
        return ERR_GET_ELEMENT;
    }
    
    *val = matrix->data[row][col];

    return OK;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (matrix == NULL) {
        return ERR_GET_ELEMENT;
    }

    if (row < 1 || row > matrix->rows) {
        return ERR_GET_ELEMENT;
    }
    if (col < 1 || col > matrix->columns) {
        return ERR_GET_ELEMENT;
    }

    matrix->data[row][col] = val;

    return OK;
}

// _____________________________Math operations_____________________________

