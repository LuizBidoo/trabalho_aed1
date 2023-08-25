#include "matrix2.h"

int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create(2);
    printf("A: \n");
    matrix_print(A, 2);
    printf("B: \n");
    Matrix *B = matrix_create(2);
    matrix_print(B, 2);
    printf("mult: \n");
    matrix_print(matrix_multiply(A, B, 2), 2);
    return 0;
}

