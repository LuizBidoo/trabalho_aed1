typedef struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
}Matrix;

Matrix* matrix_create( void )
{
    int lines = 0;
	int columns = 0;

    scanf(“%d”, &lines);
	scanf(“%d”, &columns);
    //criar uma cabeça pra cada linha, e para cada coluna
	
	Matrix* double_head = (Matrix*)malloc(sizeof(Matrix));
	double_head->right = NULL;
	double_head->right = NULL;
	double_head->line = -1; // mostra que é cabeça
	double_head->column = -1;
	
	matrix * current = double_head;

	
	for(int i = 0; i < lines; i++){  // criando lista de cabeças
		if(i == lines-1) {
			current.right = double_head;
		}else{
			current.right = (Matrix*)malloc(sizeof(Matrix));
			current = current.right;
			current.column = -1;
		}
    }
    
    current = double_head;
    for(int i = 0; i < columns; i++){    //create line

	    if(i == column-1){
		    current.below = double_head;
        } else {
	    current.below = (Matrix*)malloc(sizeof(Matrix));
	    current = current.below;
	    current.line = -1;
	    }
	
	}
    int linha = 0;
    int coluna = 0;
    int valor = 0;
    while(1){
	    scanf(“%d %d %d”, &linha, &coluna, &valor);
		// localizar linha, criar nodo e alterar ponteiros


	if(. ou 0)
		break;
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

