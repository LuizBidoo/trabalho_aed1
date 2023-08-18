#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
}Matrix;

Matrix* matrix_create_all_heads(int total_lines, int total_columns)
{
	Matrix* m = (Matrix*)malloc(sizeof(Matrix));  // matriz = cabeça dupla
	m->right = NULL;
	m->below = NULL;
	m->line = -1;
	m->column = -1;
	
	Matrix* current = m;

	for(int i = -1; i < total_lines; i++){  // criando cabeças das linhas
		if(i != total_lines-1) {
			current->below = (Matrix*)malloc(sizeof(Matrix));
			current = current->below;
			current->line = -1;
			current->right = current;
		}else{
			current->below = m; //circular
		}
    }
    
    current = m;
    for(int i = -1; i < total_columns; i++){    //criando cabeças das colunas

	    if(i != total_columns-1){
	    current->right = (Matrix*)malloc(sizeof(Matrix));
	    current = current->right;
	    current->column = -1;
		current->below = current;
        } else {
			current->right = m; //circular
	    }
	
	}

	return m;
}

Matrix* matrix_create( void )
{
	//Le de stdin os elementos diferentes de 0 e monta a matriz
    int total_lines = 0;
	int total_columns = 0;

    scanf("%d %d", &total_lines, &total_columns);
	while(total_lines == 0 || total_columns == 0)
	{
		printf("Linhas e colunas nao podem ser 0.\n");
		scanf("%d %d", &total_lines, &total_columns);
	}


	Matrix* m = matrix_create_all_heads(total_lines, total_columns);

    int line = 0;
    int column = 0;
    int info = 0;
	Matrix* current = m;

    while(1){

	    scanf("%d", &line);
		if(line == 0) return m; //talvez deveria poder ser `.` tb, mas bugou

		scanf("%d %d", &column, &info);
		// localizar line, criar nodo e alterar ponteiros

		current = m;
		for(int i = 0; i < column; i++)   // descobre cabeça da coluna certa
		{
			current = current->right;
		}
		Matrix* current_column_head = current;

		current = m;
		for(int i = 0; i < line; i++)    // descobre cabeça da linha certa 
		{
			current = current->below;
		}
		Matrix* line_head = current;

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
		temp = line_head;
		while(temp->right->column < column && temp->right->line != -1) 
		{
			temp = temp->right;
		}
			previous = temp->right;
			temp->right = current;
			current->right = previous;
//

		printf("added node:\nline: %d\ncolumn: %d\ninfo:%f\n", current->line, current->column, current->info);

    }
}


void matrix_destroy( Matrix* m )
{
    //devolve todas as células da matriz m para a área de memória disponível.
	Matrix* previous = NULL;
	while(1)
	{
		m = m->right;
		while(m->line != -1)  // deletes line except head
		{
			previous = m;
			m = m->right;
			free(previous);
		}

		previous = m; // head of previous line
		m = m->below; // goes to head of next line

		if(previous->column != -1 || previous->line != -1) // doesnt free double head
		{
			free(previous);
		}

		if(m->line == -1 && m->column == -1) // if only double head remaining
		{
			free(m);
			break;
		}
	}
}


void matrix_print( Matrix* m )
{
    // imprime a matriz m para stdout no mesmo formato usado por matrix_create().
	int lines = 0;
	int columns = 0;

	Matrix* current = m;
	while(current->below != m)
	{
		current = current->below;
		lines++;
	} 
	printf("%d ", lines);

	current = m;
	while(current->right != m)
	{
		current = current->right;
		columns++;
	} 
	printf("%d\n", columns);

	Matrix* line_head = m;
	for(int checked_lines = 0; checked_lines < lines; checked_lines++)
	{
		line_head = line_head->below;
		current = line_head->right;
		while(current != line_head) // prints whole line
		{
			printf("%d %d %.1f\n", current->line, current->column, current->info);
			current = current->right;
		}
	}
}


Matrix* matrix_add( Matrix* m, Matrix* n )
{
    //recebe como parâmetros duas matrizes e retorna a soma delas
	int total_lines = 0;
	int total_columns = 0;
	
	m = m->right;
	while(m->line != -1){
		m = m->right;
		total_lines++;
	}

	m = m->below;
	while(m->column != -1){
		m = m->below;
		total_columns++;
	}

	Matrix* new = matrix_create_all_heads(total_lines, total_columns);


	Matrix* current_new = new->below;
	Matrix* current_m = m->below->right;
	Matrix* current_n = n->below->right;
	Matrix* current_new_line_head = new->below;

	while(current_m->column != -1 && current_n->column != -1) // aloca tudo exceto os campos below dos novos nodos
	{

		while(current_m->line != -1 || current_n->line != -1)
		{
			current_new->right = (Matrix*)malloc(sizeof(Matrix));
			current_new = current_new->right;
			current_new->right = current_new_line_head; 
			
			if(current_n->line == -1 || current_m->column < current_n->column)
			{
				current_new->line = current_m->line; 
				current_new->column = current_m->column; 
				current_new->info = current_m->info;

				current_m = current_m->right;

			}  else if(current_m->line == -1 || current_n->column < current_m->column)
			{
				current_new->line = current_n->line; 
				current_new->column = current_n->column; 
				current_new->info = current_n->info;

				current_n = current_n->right;

			}  else // when equal
			{
				current_new->line = current_m->line; //could be m or n
				current_new->column = current_m->column; //could be m or n
				current_new->info = current_n->info + current_m->info;

				current_m = current_m->right;
				current_n = current_n->right;
			}
		}

		current_new = current_new_line_head->below;
		current_new_line_head = current_new_line_head->below;
		current_m = current_m->below->right;
		current_n = current_n->below->right;
	}

	current_new_line_head = new;	
	Matrix* current_new_column_head = new;	
	Matrix* previous = current_new_column_head;
	int current_new_column = 0;
	while(1) //nao sei se funciona
	{
		current_new_column_head = current_new_column_head->right;	
		if(current_new_column_head->line == -1) break;

		current_new_line_head = current_new_line_head->below;
		previous = current_new_column_head;
		current_new = current_new_line_head->right;

		current_new_column++;		
		while(current_new_line_head->column != -1)
		{
			if(current_new->column == current_new_column)
			{
				previous->below = current_new;
				previous = current_new;
			}
			current_new_line_head = current_new_line_head->below;
			current_new = current_new_line_head->right;
		}

	}

	return new;

}

/*Matrix* matrix_transpose( Matrix* m )
{
   int total_lines = 0, total_columns = 0; // contagem para criar a nova transposta
	
	Matrix* current = m;
	while(current->right != m) // contadores serão invertidos
	{
		current = current->right;
		total_lines++;
	} 
	
	current = m;
	while(current->below != m)
	{
		current = current->below;
		total_columns++;
	} 

	Matrix* new = matrix_create_all_heads(total_lines, total_columns); // cria a nova matriz transposta

	
	Matrix* current_new = new->right; // está apontando para primeira cabeça de coluna da new (vai andar pela linha)
	Matrix* current_m = m->below->right; // primeiro elemento da matriz m
	Matrix* current_new_line_head = new->right; // primeira cabeça de linha da new matrix

	while(current_new_line_head->column != -1){
		if(current_m == -1 || ){

		}
	}
	// enquanto a linha da antiga matriz for diferente de -1 e 0 (esse sendo um teste pra ver se algo ja passou)
	// vai colocando na coluna 
	//recebe como parâmetro a matriz m, 
    //retornando mT – a transposta de m 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).

}*/

float matrix_getelem(Matrix* m, int x, int y)
{
    //retorna o valor do elemento (x, y) da matriz m.
    for(int line = 0; line < x; line++)
	{
		m = m->below;
	}

	for(int column = 0; column < y; column++)
	{
		m = m->right;
	}

	return m->info;
}


void matrix_setelem( Matrix* m, int x, int y, float elem ) 
{
	//atribui ao elemento (x, y) da matriz m o valor elem.
    for(int line = 0; line < x; line++)
	{
		m = m->below;
	}

	for(int column = 0; column < y; column++)
	{
		m = m->right;
	}

	m->info = elem;
}