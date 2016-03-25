#include <stdio.h>

/*
PROBLEMA: eh dado um array A de tamanho N,
	retorne um array com todos os elementos
	menores ou iguais a 10 de um lado
	e elementos maiores que 10 do outro lado
*/

int A[] = {2, 3, 10, 11, 25, 3, 2, 40, 12};

void processo()
{
	int i, j = 0;
	for(i = 0; i < 9; i++)
	{
		if(A[i] <= 10)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			++j; 
		}
	}	
	
	//print array
}

int main()
{
	processo();
}


