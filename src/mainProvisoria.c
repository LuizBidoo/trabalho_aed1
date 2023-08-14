#include "matrix.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_getelem(A, 1, 1);
    return 0;
}

