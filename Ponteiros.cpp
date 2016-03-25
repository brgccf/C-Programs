#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = 'a';
	char *pch = &ch; //armazena o endereço de memoria.
	*pch = 'b'; //altera o valor do endereço de memoria.
	printf("%c\n", ch);
	
	int a = 3;
	int *pa = NULL; //null deve ser maiusculo
	pa = &a;
	a = 5;
	printf("%d\n", *pa); //*pa imprime o conteudo do endereço
	
	//encontrando o endereço de memoria do ponteiro ja criado
	//int **ppa = &pa; 
	int *ppa = (int*) &pa;
	printf("%p\n", &a);
	printf("%p\n", &pa);
	printf("%p\n", &ppa);
	printf("%p\n", ppa);
	
	//alocação dinamica: declarar um array com o tamanho da entrada do teclado 
	int n;
	scanf("%d", &n);
	//malloc: funçao que solicita ao sistema operacional a quantidade de memoria necessaria 
	//para seu programa
	int *A = (int *) malloc(n*sizeof(int)); //cria um bloco de memoria do tamanho do array pedido
	printf("%p\n", A);
	A[0] = 3;
	//A[i] == *(A + i*sizeof(int))
	int val = *A;
	printf("val = %d\n", val);
	
	//liberando a memoria:
	free(A);
	A = NULL;
	
	return 0;
}
