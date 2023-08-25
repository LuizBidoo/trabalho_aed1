#include "matrix2.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create(2);
    printf("A: \n");
    matrix_print(A, 2);
    printf("transposed: \n");
    matrix_print(matrix_transpose(A, 2), 2);
    return 0;
}

