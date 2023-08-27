#include "matrix.h"
#include <time.h>

int main( void ) {
    srand(time(NULL));
    time_t start = time(NULL);
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create_random(5000);
    //matrix_print( A );
    Matrix *B = matrix_create(5000); 
    //matrix_print( B );
    Matrix *C = matrix_add( A, B, 5000 ); 
    //matrix_print( C );
    matrix_destroy( C, 5000 );
    C = matrix_multiply( A, B, 5000 ); 
    //matrix_print( C );
    matrix_destroy( C, 5000 );
    C = matrix_transpose( A, 5000 ); 
    //matrix_print( C );
    matrix_destroy( C, 5000 );
    matrix_destroy( A, 5000 );
    matrix_destroy( B, 5000 );

    time_t end = time(NULL);
    printf("Tempo de execucao: %ld", (end-start));

    return 0;
    
}

