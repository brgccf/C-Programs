#include <stdio.h>

unsigned int amp, freq, total_casos;
unsigned int eh_um = 0;

int ler_total_casos()
{
	if (scanf("%d", &total_casos) != 1) return 0;
	else return 1;
}

int ler_dados()
{
	while(scanf("%d \n %d", &amp, &freq) != EOF) return 1;
}

void processo_1()
{
	if(amp == 1) 
	{
		eh_um = 1;
		return;
	}
	int i, j;
	int limite = (amp*2)-1;
	int height;
	for(i = 1; i < limite; i++)
	{
		height = i;
		if(height > amp) break;
		for(j = i; j > 0; j--)
		{
			printf("%d", height);
		}
		printf("\n");
	}
	
}

void processo_2()
{
	int i, j;
	int height = amp-1;
	for(i = amp-1; i > 0; i--)
	{
		for(j = i; j > 0; j--)
		{
			printf("%d", height);
		}
		height--;
		if(height)	printf("\n");
	}
	freq--;
	if(freq)
	{
		printf("\n\n");
		processo_1();
	}
}

int main()
{

	int nao_eh_primeira_vez = 0;
	ler_total_casos();
	int contador = 1;

	while(ler_dados())
	{
		if(nao_eh_primeira_vez) printf("\n\n");
		processo_1();
		if(eh_um){
			while(freq)
			{
				printf("1");
				freq--;
				if(freq)printf("\n\n");
				
			}
			eh_um = 0;
		}
		while(freq) processo_2();
		contador++;
		nao_eh_primeira_vez = 1;
		if(contador > total_casos)
		{
			printf("\n");
			break;	
		}
	}
	
	return 0;
}


