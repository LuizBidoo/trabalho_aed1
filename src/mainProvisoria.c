#include "matrix2.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create(2);
    matrix_print(matrix_multiply(A,A, 2), 2);
    matrix_destroy(A, 2);
    return 0;
}

