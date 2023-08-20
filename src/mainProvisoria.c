#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print(A);
    Matrix *B = matrix_create();
    matrix_print(B);
    Matrix* C = matrix_add(A, B);
    matrix_destroy(C);
    matrix_destroy(B);
    matrix_destroy(A);
    return 0;
}

