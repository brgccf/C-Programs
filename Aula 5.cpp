/*--------AULA 5 - Custos computacionais ------

PROBLEMA 1 - ARRAY COM 20 POSI��ES COM 20 NUMEROS, QUAL O MAIOR?

Solu��o:
#include <stdio.h>

#define MAX 20

int array[MAX] = {2, 5, 1, 20, 12, 13, 12, 8, 4, 11, 8, 9, 3, 7, 17, 6, 14, 16, 10, 19};

int calcular_max(int A[]) 
{
	int i, m = A [0];
	for(i = 1; i < MAX; i++)
		if(m < A[i]) m = A[i];
	return m;	
}

int main()
{
	printf("maximo = %d/n", calcular_max(array));
	return 0;
}

*Constantes computacionais: Os algoritmos possuem um custo que pode ser representado por
um valor n. Como nunca podemos resumir em somente um �nico valor espec�fico, fazemos isso com um conjunto: O Big O
O(n) � o conjunto de todas as fun��es que crescem ou t�o r�pido, ou mais lentamente do que n (nunca mais r�pido).

PROBLEMA 2: Implemente uma ordena��o

Solu��o: www.cin.ufpe.br/~pmmc/if724/Aula5
//define permuta��o
//define max 10000000
//define __PRO_MODE__

int array[MAX];

void bubblesort(int A[], int i0, int n)
{
	int i, j;
	for(i = n; i > i0; --i){
		for(j=i0; j < i; j++){
			if(A[j] > A[j+1])
				PERM(A[j], A[j+1]);
	    }
	}
}

#ifdef __PRO_MODE__
void quicksort(int A[], int l, int r)
{
	if(l+1 >= r)





PROBLEMA 3 : fibonacci


PROBLEMA 4: DADO UM N, IMPRIMIR TODOS OS PRIMOS AT� N






/*
