#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print(A);
    matrix_setelem(A, 2, 1, 0);
    matrix_print(A);
    return 0;
}

