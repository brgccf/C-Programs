#include <stdio.h>
#include <math.h>
#define BILHAO 1000000000
//aula 9, criar um algoritmo log (n)
/*

Problema: A^B = ? (o mod eh apenas
para nao ter que usar Big Num)
ideal utilizar operadores bit a bit
*/

int aux_exp(int A, int B)
{
	int i, res = 1, v = A;
	for(i = 0; (1<<i) < B; i++)
	{
		if(B & (1<<i))
		{
			res*=v;
			res %= 10000;
		}
		printf("A^%d mod 10000 = %d\n", (1<<i), v);
		v *= v;
		v %= 10000;
	}
	
	printf("%d\n", res);
	
	return res;
	
}

int main() 
{
	int A, B;
	scanf("%d %d",&A,&B);
	aux_exp(A,B);
	//printf("resultado = %Lu\n", aux_exp(A,B));
	return 0;
}
