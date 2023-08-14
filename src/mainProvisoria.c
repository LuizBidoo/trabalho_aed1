#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    printf("%f\n", matrix_getelem(A, 1, 1));
    matrix_setelem(A, 1, 1, 2);
    printf("%f\n", matrix_getelem(A, 1, 1));
    return 0;
}

