#include <stdio.h>

/*
	1- imprimir de tras pra frente
	2- imprimir de frente pra tras
	os numeros de 1 ate n
*/

int n;

int read_data()
{
	return scanf("%d", &n) == 1;
}

void iterativo()
{
	int i;
	printf("iterativamente");
	for(i = 1; i <= n; i++) printf(" %d", i);
	for(i = n; i >= 1; i--) printf("%d", i);
	printf("\n");
}


