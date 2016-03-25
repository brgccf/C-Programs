#include <stdio.h>
#include <stdlib.h>
// problema 1 aula 7
#define MAX 1000000

int n;
unsigned int produtorio[MAX]; 

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	int i;
	//o array sera preenchido ate o n de entrada. temos que calcular o produtorio ate esse valor n
	for(i = 0; i < n; i++) scanf("%d", &produtorio[i]);
	return 1;
}

void processo(unsigned int n)
{
	int i,j;
	int resultado[n];
	int multiplicador = 1;
	for(i = 0; i < n; i++)
	{
		 for(j = 0; j < n; j++)
		 {
		 	if(j != i) multiplicador *= produtorio[j];  
		 }
		 resultado[i] = multiplicador;
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d ", resultado[i]);
	}
	printf("\n");
	/*SOLUÇÃO
	EASY_MODE
	int i, j;
	for(i = 0; i< n; i++){
		int prod = 1;
		for(j=0; j < n; j++)
			if(i != j) prod *= a[i];
		printf("%d ", prod);
	}
	
	HARD_MODE
	multiplica todo mundo e divide pelo valor atual!!
	obs.: devemos ter cuidado quando houver um zero no produtorio!
	obs2.: se houver mais de um zero, o produtorio somente dará zero!!
	int i, prod = 1, nz = 0;
	for(i = 0; i < n; i++) if(a[i]) nz++;
	if(nz > 1){
		for(i = 0; i < n; i++) printf ("0 ");
		printf("\n";
		//obs: o return abaixo fará o programa sair da função inteira.
		return;
	}
	
	for(i = 0; i< n; i++) if(a[i]) prod *= a[i];
	for(i = 0; i< n; i++){
	 	if(a[i])	printf ("%d ", prod / a[i]);
	 	else	printf ("%d ", prod);
	 
	}
	printf("\n");
	*/
}

int main()
{
	while(ler_dados())
	{
		processo(n);
	}
	return 0;
}
