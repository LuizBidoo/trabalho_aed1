#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef float* Matrix;

Matrix* matrix_create( unsigned int m )
{
    srand(time(0));
    float** matrix = (float**)malloc(sizeof(float*)*m);
    for(int i = 0; i < m; i++)
    {
        matrix[i] = (float*)malloc(sizeof(float)*m);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrix[i][j] = rand()%100;
        }
    }

    return matrix;
}

void matrix_print ( Matrix* matrix, unsigned int m )
{
    for(int i = 0; i < m; i++)
    {  
        for(int j = 0; j < m; j++)
        {
            printf("%.1f\n", matrix[i][j]);
        }
    }

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