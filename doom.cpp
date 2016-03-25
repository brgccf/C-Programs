#include <stdio.h>
#include <stdlib.h>
//deve somar (m+n) e dividir pelo MDC (m, n)

unsigned int total_casos;
long long unsigned int m, n;

int ler_total_casos()
{
	if(scanf("%d", &total_casos) != 1) return 0;
	else return total_casos;
}

int ler_dados()
{
	while(scanf("%lld %lld", &m, &n) != EOF) return 1;
	
}

int MDC(int a, int b)
{
	int resto;
	
	while(b > 0)
	{
		resto = a % b;
		a = b;
		b = resto;
	}
	
	return a;
}

long long unsigned int processo()
{
	int resultado = 0;
	int soma = (m + n);
	if(m == 1 && n == 1) return 2;
	//encontrando MDC (m, n)
	int mdc = MDC(m, n);
	resultado = soma/mdc;
	return resultado;
}

int main()
{
	ler_total_casos();
	int contador = 1;
	while(ler_dados())
	{
		long long unsigned int resultado = processo();
		printf("Case %d: %lld\n", contador, resultado);
		contador++;
		if(contador > total_casos) break;
	}
	return 0;
}


