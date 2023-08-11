#include "matrix.h"

struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
};



int main( void ) {
    typedef struct matrix Matrix;

    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print( A );
    Matrix *B = matrix_create(); 
    matrix_print( B );
    Matrix *C = matrix_add( A, B ); 
    matrix_print( C );
    matrix_destroy( C );
    C = matrix_multiply( A, B ); 
    matrix_print( C );
    matrix_destroy( C );
    C = matrix_transpose( A ); 
    matrix_print( C );
    matrix_destroy( C );
    matrix_destroy( A );
    matrix_destroy( B );
    return 0;
}

