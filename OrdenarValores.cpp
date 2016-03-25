#include <stdio.h>
#include <stdlib.h>

//DEFINE PARA PERMUTAR VALORES:
#define PERM(x,y) {int __t__ = (x); (x) = (y); (y) = __t__;}

int array[20] = {3, 6, 2, 8, 4, 6, 9, 10, 24, 65, 1, 4, 5, 7, 22, 55, 77, 32, 51, 41};

void ordenar()
{
	int i, j;
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if(array[j] < array[i]) PERM(array[i], array[j]);
		}
	}
}

int main()
{
	printf("Antes:\n");
	int j;
	for(j = 0; j < 20; j++)
	{
		printf("%d ", array[j]);
	}
	printf("\n");
	ordenar();
	printf("Depois: \n");
	int i;
	for(i = 0; i < 20; i++)
	{
		printf("%d ", array[i]);
	}
}

