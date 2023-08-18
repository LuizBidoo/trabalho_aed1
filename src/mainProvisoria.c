#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    Matrix *B = matrix_create();
    matrix_print(A);
    printf("\n");
    matrix_print(B);
    printf("\n");
    Matrix* Z = matrix_add(A, B);
    matrix_print(Z);

    matrix_destroy(A);
    matrix_destroy(B);
    matrix_destroy(Z);
    return 0;
}

