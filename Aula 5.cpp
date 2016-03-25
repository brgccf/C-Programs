/*--------AULA 5 - Custos computacionais ------

PROBLEMA 1 - ARRAY COM 20 POSIÇÕES COM 20 NUMEROS, QUAL O MAIOR?

Solução:
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
um valor n. Como nunca podemos resumir em somente um único valor específico, fazemos isso com um conjunto: O Big O
O(n) é o conjunto de todas as funções que crescem ou tão rápido, ou mais lentamente do que n (nunca mais rápido).

PROBLEMA 2: Implemente uma ordenação

Solução: www.cin.ufpe.br/~pmmc/if724/Aula5
//define permutação
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


PROBLEMA 4: DADO UM N, IMPRIMIR TODOS OS PRIMOS ATÉ N






/*
