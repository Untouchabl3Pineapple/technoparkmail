#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define OK                                      0
#define ERR_ROWS_FILL                           (-1)
#define ERR_COLUMNS_FILL                        (-2)
#define ERR_GET_ELEMENT                         (-3)

typedef struct
{
    double **data;
    size_t rows;
    size_t columns;
} Matrix;

// Init/release operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
int free_matrix(Matrix* matrix);
void printMatrix(Matrix* matrix);

// Basic operations
int get_rows(const Matrix* matrix, size_t* rows);
int get_cols(const Matrix* matrix, size_t* cols);
int get_elem(const Matrix* matrix, size_t row, size_t col, double* val);
int set_elem(Matrix* matrix, size_t row, size_t col, double val);

//Math operations
Matrix* mul_scalar(const Matrix* matrix, double val);
Matrix* transp(const Matrix* matrix);

Matrix* sum(const Matrix* l, const Matrix* r);
Matrix* sub(const Matrix* l, const Matrix* r);
Matrix* mul(const Matrix* l, const Matrix* r);

// Extra operations
int det(const Matrix* matrix, double* val);
Matrix* adj(const Matrix* matrix);
Matrix* inv(const Matrix* matrix);

#endif //_MATRIX_H_
