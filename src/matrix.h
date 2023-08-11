#include <stdlib.h>
#include <stdio.h>

typedef struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
}Matrix;

Matrix* matrix_create( void )
{
    //lê de stdin os elementos diferentes de zero de uma matriz 
    //e monta a estrutura especificada acima. 
    //A entrada consiste dos valores de m e n (número de linhas e de colunas da matriz) 
    //seguidos de triplas (i, j, valor) 
    //para os elementos diferentes de zero da matriz. Por exemplo, para a matriz da Figura 1, a entrada seria:
}

void matrix_destroy( Matrix* m )
{
    //devolve todas as células da matriz m para a área de memória disponível.
}

void matrix_print( Matrix* m )
{
    // imprime a matriz m para stdout no mesmo formato usado por matrix_create().
}

Matrix* matrix_add( Matrix* m, Matrix* n )
{
    //recebe como parâmetros as matrizes m e n, 
    //retornando a soma das mesmas 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).

}

Matrix* matrix_multiply( Matrix* m, Matrix* n)
{
    //recebe como parâmetros as matrizes m e n, retornando a multiplicação das mesmas 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).
}

Matrix* matrix_transpose( Matrix* m )
{
    //recebe como parâmetro a matriz m, 
    //retornando mT – a transposta de m 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).

}

float matrix_getelem( Matrix* m, int x, int y)
{
    //retorna o valor do elemento (x, y) da matriz m.
    //void matrix_setelem( Matrix* m, int x, int y, float elem ): 
    //atribui ao elemento (x, y) da matriz m o valor elem.

}

