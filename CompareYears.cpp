#include <stdio.h>
//Recebe dois inteiros (anos) como entrada e quantos anos bissextos há entre eles

int a, b;

int ler_dados()
{
	if (scanf("%d%d", &a, &b) != 2) return 0;
	return 1; 
}

int processo()
{
	int contador = 0;
	int delta = b - a;
	while(delta >= 100)
	{
		if((delta%4) == 0)
		{
			if((delta%100) == 0)
			{
				if((delta%400) == 0) contador++;			
			}
		}
		contador += 24;
		delta -= 100;
	}
	while(delta <= 100 & delta > 0)
	{
		contador += 3;
		if((a%4) == 0)
		{
			if((a%100) == 0)
			{
				if((a%400) != 0) contador--;			
			}
		}
		delta -= 10;
	}	
	
	return contador;
	
	
}

int main()
{
	while(ler_dados())
	{
		int resultado = processo();
		printf("Resultado = %d anos\n", resultado);
	}
	return 0;
}
