#include <stdio.h>
//dado um array A preenchido ordenadamente, diga o se o elemento N existe

unsigned int n;
unsigned int A[12] = {1, 3, 5, 6, 9, 10, 13, 16, 19, 21, 24, 34};
unsigned int existe = 1;

void search()
{
	int inicio = 0, fim = 11;
	int index = 11/2;
	while(n != A[index])
	{
		if(n > A[index]) 
		{
			inicio = index+1;
			index = (int)((fim+inicio)/2);
		}
		else if(n < A[index])
		{
			fim = index;
			index = (int)(inicio+fim)/2;
		}
		if (inicio == fim)
		{
			printf("Nao existe!\n");
			existe = 0;
			break;
		}
		
	} 
	if(existe)
	{
		printf("Resultado: %d\n", index);
	}
	existe = 1;
	
}

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

int main()
{
	int result;
	while(ler_dados())
	{
		search();
	}
		
	return 0;
}
