#include <stdio.h>

#define CEM_MILHOES 100000000
#define DEZ_MILHOES 10000000
#define BILHAO 1000000000
#define MILHAO 1000000
#define CEM_MIL 100000

//dado um inteiro 0<=N<= 10000 , calcular seu fatorial e retornar o maior inteiro do resultado.

unsigned int n;
unsigned int N;

int ler_dados()
{
	while(scanf("%d", &n) != EOF) return 1;
	return 0;
}

unsigned long long int processo()
{
	if(n == 0) return 1;
	int fat;
	for(fat = 1; n > 0; n--)
	{
		if(fat > CEM_MIL) fat %= CEM_MIL; 
		fat *= n;
		if(fat > MILHAO) fat %= MILHAO;
		if((fat % 10) == 0) fat = fat/10;
	}
	int resultado = fat%10;
	
	return resultado;
}

int main()
{
	while(ler_dados())
	{
		N = n;
		unsigned int resultado = processo();
		printf("%d -> %d\n", N, resultado);
		
	}
	
	return 0;
}
