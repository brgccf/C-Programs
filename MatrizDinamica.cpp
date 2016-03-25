#include <stdio.h>
#include <stdlib.h>
//matriz tridimensional dinamica
int main()
{
	int n, m, k, i, j;
	scanf("%d%d%d", &n, &m, &k);
	int ***a = (int***) malloc(sizeof(int**)*n); //array de ponteiro para ponteiro para ponteiro
	for(i = 0; i < n; i++)
	{
		a[i] = (int**) malloc(sizeof(int*)*m); //array de ponteiro para inteiro
	}
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < m; j++)
		{
			a[i][j] = (int*) malloc(sizeof(int)*k); //array para inteiro
		}
	}
	//acessamos com a[i][j][k]
	//obs.: liberamos a memoria alocada de tras pra frente
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			free(a[i][j]);
		}
	}
	for(i = 0; i < n; i++) free(a[i]);
	
	
	//desafio : como alocar as dimensoes dinamicamente?
	
	return 0;
}
