#include <stdio.h>
//problema: dados dois arrays A e B de inteiros ordenados, crie um array C com a união
//desses dois e ordene os termos
int A[10] = {1, 5, 7, 9, 11, 18, 20, 23, 25, 29};
int B[10] = {2, 3, 4, 8, 12, 15, 17, 18, 19, 22};

int C[20];

void preenche_C()
{
	int i;
	for(i = 0; i < 10; i++)
	{
		C[i] = A[i];
	}
	for(i = 10; i < 20; i++)
	{
		C[i] = B[i-10];
	}
}

void ordena_C()
{
	int i = 0, j = 0;
	int k;
	for(k = 0; k < 20; k++)
	{
		if(i > 9)
		{
			if(j > 9) break;
			else
			{
				while(j <= 9)
				{
				
					C[k] = B[j];
					j++;
					k++;
				}
			}
		}
		else if(j > 9)
		{
			if(i > 9) break;
			else
			{
				while(i <= 9)
				{
					C[k] = A[i];
					i++;
					k++;
				}
			}
		}
		if(A[i] <= B[j])
		{
			C[k] = A[i];
			i++;
		}
		else if(B[j] < A[i])
		{
			C[k] = B[j];
			j++;
		}
	}
	
	
}

void imprime_C()
{
	int i;
	for(i = 0; i < 20; i++)
	{
		printf("%d ", C[i]);	
	}
	
}

int main()
{
	preenche_C();
	imprime_C();
	printf("\n");
	ordena_C();
	imprime_C();
	
}
