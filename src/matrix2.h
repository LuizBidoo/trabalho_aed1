#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef float Matrix;

Matrix* matrix_create( unsigned int m )
{
    srand(time(0));
    float Matrix[m][m];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Matrix[i][j] = rand();
        }
    }

    return &Matrix[0][0];
}

void matrix_print ( Matrix Matrix[][] )
{
    Matrix[0][0] = 0;

}

Matrix* matrix_add ( Matrix* m )
{

}

Matrix* matrix_multiply ( Matrix* m )
{

}

Matrix* matrix_transpose ( Matrix* m )
{

}