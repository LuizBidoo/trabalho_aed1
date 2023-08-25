#include "matrix2.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create(4);
    printf("A: \n");
    matrix_print(A, 4);
    matrix_destroy(A, 4);
    return 0;
}

