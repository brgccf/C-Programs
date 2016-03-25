#include <stdio.h>
//recebe um inteiro de entrada e diz se o ano é bissexto ou não
int a;
int ler_dados()
{
	if (scanf("%d", &a) != 1) return 0;
	return 1;
}

int processo()
{
	if(((a%4) == 0))
	{
		if((a%100) == 0)
		{
			if((a%400) == 0) return 1;
			else return 0;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	while (ler_dados())
	{
		int resultado = processo();
		if (resultado)
		{
			printf ("eh bissexto!\n");
		}
		else
		{
			printf ("Nao eh bissexto\n");
		
		}
	}
}
