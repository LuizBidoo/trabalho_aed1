#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print(A);
    Matrix* B = matrix_transpose(A);
    matrix_print(B);
    matrix_destroy(A);
    matrix_destroy(B);
    return 0;
}

