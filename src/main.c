#include "matrix.h"
#include <time.h>

int main( void ) {
    time_t start = time(NULL);
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create_random(50);
    //matrix_print( A );
    Matrix *B = matrix_create_random(50); 
    //matrix_print( B );
    Matrix *C = matrix_add( A, B ); 
    //matrix_print( C );
    matrix_destroy( C );
    C = matrix_multiply( A, B ); 
    //matrix_print( C );
    matrix_destroy( C );
    C = matrix_transpose( A ); 
    //matrix_print( C );
    matrix_destroy( C );
    matrix_destroy( A );
    matrix_destroy( B );
    time_t end = time(NULL);
    printf("Tempo de execucao: %ld", (end-start));

    return 0;
    
}

