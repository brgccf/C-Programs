#include <stdio.h>

unsigned int n;

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

int sqrt(int inicio, int fim)
{
	int i = (inicio+ fim)/2;
	if(i*i == n) return i;
	else if(inicio==fim-1) return i;
	else if (i*i > n) sqrt(inicio, i);
	else sqrt(i, fim);
		
}

int main()
{
	ler_dados();
	int result = sqrt(0, n);
	printf("Resultado: %d\n", result);
	return 0;
}

