#include <stdio.h>
//problema de entrevista do Google: Dada uma matriz A ordenada por linha e por coluna de tamanho
//M e N respectivamente, ao darmos um número qualquer C, queremos saber se este está dentro da matriz.
int M, N;
int A[100][100];

int ler_dados()
{
	if(scanf("%d%d", &M, &N) != 2) return 0;
	int i, j;
	for(i = 0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	return 1;
	
}

void imprime_matriz()
{
	int i, j;
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", A[M][N]);
			
		}
		printf("\n");
	}
}

int search()
{
	int key;
	printf("\nDigite o número procurado: ");
	scanf("%d", &C); 
	//verificando se existe C na matriz
	int i=0, j = N-1;
	while(1)
	{
		if (i == N) break;
		if(j == -1) break;
		if(key > A[i][j]) ++i;
		else if ( key < A[i][j]) --j;
		else return 1;
	} 
	return 0;
}

int main()
{
	ler_dados();
	printf("Sua matriz atual é \n");
	imprime_matriz();
	int resultado = search();
	if(resultado) printf("Achou!");
	return 0;
}
