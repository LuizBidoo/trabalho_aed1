#include <stdlib.h>
#include <stdio.h>

typedef struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
}Matrix;

void count_lines_and_columns( int* total_lines, int* total_columns, Matrix* m )
{
	m = m->right;
	while(m->line != -1){
		m = m->right;
		*total_lines = *total_lines + 1;
	}

	m = m->below;
	while(m->column != -1){
		m = m->below;
		*total_columns = *total_columns + 1;
	}	
}

Matrix* matrix_create_all_heads( int total_lines, int total_columns )
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

void matrix_insert_below_camps( Matrix* new )
{
	Matrix* current_new = new->below;
	Matrix* current_new_line_head = new->below;
	Matrix* current_new_column_head = new->right;	
	Matrix* previous = current_new_column_head;
	int current_column = 1;
	while(current_new_column_head->line != -1)
	{
		while(current_new_line_head->column != -1)
		{
			do{
				current_new = current_new->right;
			}while(current_new->column != current_column && current_new->line != -1);

			if(current_new->column == current_column)
			{
				previous->below = current_new;
				current_new->below = current_new_column_head;
				previous = current_new;
			}
			current_new_line_head = current_new_line_head->below;
			current_new = current_new_line_head;
		}
		current_new_line_head = current_new_line_head->below;
		current_new_column_head = current_new_column_head->right;
		previous = current_new_column_head;
		current_column++;
		current_new = current_new_line_head;
	}
}

Matrix* matrix_create( void )
{
	//Le de stdin os elementos diferentes de 0 e monta a matriz
    int total_lines = 0;
	int total_columns = 0;

    scanf("%d %d", &total_lines, &total_columns);
	while(total_lines == 0 || total_columns == 0)
	{
		printf("Nem linhas nem colunas podem ser 0.\n");
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
	
	count_lines_and_columns(&total_lines,&total_columns, m);

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

	matrix_insert_below_camps(new);

	return new;

}

Matrix* matrix_multiply( Matrix* m, Matrix* n )
{
	//recebe como parâmetros as matrizes m e n, retornando a multiplicação das mesmas 
	int total_lines_m = 0;
	int total_columns_m = 0;
	int total_lines_n = 0;
	int total_columns_n = 0;

	count_lines_and_columns(&total_lines_m, &total_columns_m, m);
	count_lines_and_columns(&total_lines_n, &total_lines_n, m);

	Matrix* new = matrix_create_all_heads(total_lines_m, total_columns_n);

	Matrix* current_new = new->below;
	Matrix* current_new_line_head = new->below;
	Matrix* current_m = m->below->right;
	Matrix* current_m_line_head = m->below;
	Matrix* current_n = n->right->below;
	Matrix* current_n_column_head = n->right;
	int sum = 0;	
	while(current_m_line_head != m)
	{
		while(current_m->column == current_n->line)
		{
			if(current_m->line != -1 && current_n->column != -1)
			{
				sum = (current_m->info * current_n->info) + sum;
				current_m = current_m->right;
				current_n = current_n->below;
			}
			if(current_m->line == -1 || current_n->column == -1)
			{
				if(sum != 0)
				{
					current_new->right = (Matrix*)malloc(sizeof(Matrix));
					current_new = current_new->right;

					current_new->line = current_n->below->column;
					current_new->column = current_m->right->line;
					current_new->right = current_new_line_head;
					current_new->info = sum;
					sum = 0;
				}

				current_m_line_head = current_m_line_head->below;
				current_m = current_m_line_head->right;
				current_n_column_head = current_n_column_head->below;
				current_n = current_n_column_head->right;
				break;
			}	
		}

		while(current_m->column != current_n->line)
		{
			if(current_m->line == -1 || current_n->column == -1) break;

			if(current_m->column < current_n->line)
			{
				current_m = current_m->right;
			} else if(current_n->line < current_m->column)
			{
				current_n = current_n->below;
			}
		}
	
	}
	return new;
}

Matrix* matrix_transpose( Matrix* m )
{
	//retorna mT – a transposta de m 
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

	Matrix* new = matrix_create_all_heads(total_lines, total_columns); 

	
	Matrix* current_new = new->below;
	Matrix* current_new_line_head = new->below;
	Matrix* current_m = m->right->below; 
	while(current_m->line != -1)
	{
		while(current_m->column != -1)
		{
			current_new->right = (Matrix*)malloc(sizeof(Matrix));
			current_new = current_new->right;

			current_new->column = current_m->line;
			current_new->line = current_m->column;
			current_new->info = current_m->info;
			current_new->right = current_new_line_head;

			current_m = current_m->below;
		}
		current_m = current_m->right->below;
		current_new_line_head = current_new_line_head->below;
		current_new = current_new_line_head;
	}

	matrix_insert_below_camps( new );

	return new;
}

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