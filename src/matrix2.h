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

    int temp = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            temp = rand()%200;
            if(temp > 50)
            {
                matrix[i][j] = 0;
            } else{
                matrix[i][j] = temp;
            }
        }
    }

    return matrix;
}

void matrix_destroy ( Matrix* matrix, unsigned int m)
{
    for(int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void matrix_print ( Matrix* matrix, unsigned int m )
{
    for(int i = 0; i < m; i++)
    {  
        for(int j = 0; j < m; j++)
        {
            printf("%d %d %.1f\n", i, j, matrix[i][j]);
        }
    }
}

Matrix* matrix_add ( Matrix* matrix, Matrix* matrix_2, unsigned int m )
{
    float** new = (float**)malloc(sizeof(float*)*m);
    for(int i = 0; i < m; i++)
    {
        new[i] = (float*)malloc(sizeof(float)*m);
    }

    for(int i = 0; i < m; i++)
    {  
        for(int j = 0; j < m; j++)
        {
            new[i][j] = matrix[i][j] + matrix_2[i][j]; 
        }
    }
}

Matrix* matrix_multiply ( Matrix* matrix, Matrix* matrix_2, unsigned int m )
{
    float** new = (float**)malloc(sizeof(float*)*m);
    for(int i = 0; i < m; i++)
    {
        new[i] = (float*)malloc(sizeof(float)*m);
    }

    int sum = 0;
    for(int line = 0; line < m; line++)
    {
        for(int col = 0; col < m; col++)
        {
            for(int i = 0; i < m; i ++)
            {
                sum+= matrix[line][i] * matrix_2[i][col];
            }
            new[line][col] = sum;
            sum = 0;
        }
    }

    return new;
}

Matrix* matrix_transpose ( Matrix* matrix, unsigned int m )
{
    float** new = (float**)malloc(sizeof(float*)*m);
    for(int i = 0; i < m; i++)
    {
        new[i] = (float*)malloc(sizeof(float)*m);
    }

    for(int line = 0; line < m; line++)
    {
        for(int col = 0; col < m; col++)
        {
            new[line][col] = matrix[col][line];
        }
    }
    return new;
}