#include "matrix.h"
#include <time.h>

int main( void ) {
    time_t start = time(NULL);
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create_random(5000);
    Matrix *B = matrix_create_random(5000);
    matrix_destroy(A);
    matrix_destroy(B);

    time_t end = time(NULL);
    printf("Tempo de execucao: %ld", (end-start));

    return 0;
    
}
