#include <stdlib.h>
#include <stdio.h>

typedef struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
}Matrix;

Matrix* matrix_create( void )  // deve funcionar com entrada de dados sem ordem de linhas e colunas tb
{
    int total_lines = 0;
	int total_columns = 0;

    scanf("%d %d", &total_lines, &total_columns);
	if(total_lines == 0 && total_columns == 0) return;

	Matrix* double_head = (Matrix*)malloc(sizeof(Matrix));
	double_head->right = NULL;
	double_head->below = NULL;
	double_head->line = -1; // mostra que é cabeça
	double_head->column = -1;
	

	Matrix* current = double_head;

	for(int i = -1; i < total_lines; i++){  // criando cabeças das linhas
		if(i != total_lines-1) {
			current->below = (Matrix*)malloc(sizeof(Matrix));
			current = current->below;
			current->line = -1;
			current->right = current;
		}else{
			current->below = double_head; //circular
		}
    }
    
    current = double_head;
    for(int i = -1; i < total_columns; i++){    //criando cabeças das colunas

	    if(i != total_columns-1){
	    current->right = (Matrix*)malloc(sizeof(Matrix));
	    current = current->right;
	    current->column = -1;
		current->below = current;
        } else {
			current->right = double_head; //circular
	    }
	
	}

    int line = 0;
    int column = 0;
    int info = 0;

    while(1){

	    scanf("%d", &line);
		if(line == '.' || line == 0) break;

		scanf("%d %d", &column, &info);
		// localizar line, criar nodo e alterar ponteiros

		current = double_head;
		for(int i = 0; i < column; i++)   // descobre cabeça da coluna certa
		{
			current = current->right;
		}
		Matrix* current_column_head = current;

		current = double_head;
		for(int i = 0; i < line; i++)    // descobre cabeça da linha certa 
		{
			current = current->below;
		}
		Matrix* current_line_head = current;

		///////////////////////////////////////////////////////////////////////////////////////// 

// criando nodo no lugar certo
		Matrix* temp = current_column_head;
		while(temp->below->line < line && temp->below->column != -1) 
		{
			temp = temp->below;
		}

			Matrix* previous = temp->below;
			temp->below = (Matrix*)malloc(sizeof(Matrix));
			current = temp->below;

			current->column = column;
			current->line = line;
			current->info = info;
			current->below = previous;
//

// adicionando current->right
		temp = current_line_head;
		while(temp->right->column < column && temp->right->line != -1) 
		{
			temp = temp->right;
		}
			previous = temp->right;
			temp->right = current;
			current->right = previous;
//

		//printf("added node:\nline: %d\ncolumn: %d\ninfo:%f\n", current->line, current->column, current->info);

    }
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

