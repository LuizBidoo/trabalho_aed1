#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print(A);
    matrix_setelem(A, 2, 2, 0);
    matrix_print(A);
    return 0;
}

