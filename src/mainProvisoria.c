#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print(matrix_multiply(A,A));
    matrix_destroy(A);
    return 0;
}

