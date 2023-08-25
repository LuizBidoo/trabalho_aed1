#include "matrix2.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create(5);
    matrix_print(A, 5);
    return 0;
}

