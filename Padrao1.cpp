#include <stdio.h>
/*
*

*
**

*
**
***

*
**
***
****
...
*/

unsigned int n;

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

void processo()
{
	int i, contador = 1;
	while(1)
	{
		for(i = 0; i < contador; i++)
		{
			printf("*");
		}
		printf("\n");
		if(contador == n) break;
		contador++;
	}
}

int main()
{
	if(ler_dados())
	{
		processo();
	}	
	else printf("Erro de leitura");
	return 0;
}
