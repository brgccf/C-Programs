#include <stdio.h>
#include <stdlib.h>

signed long long int A, B, L; 
int contador = 1;
int ler_valores()
{
	scanf("%lli%lli", &A, &L);
	if(A < 0 && L < 0) return 0;
	else 
	{
		B = A;
		return 1;
	}
}


int processo()
{
	while(A > 1)
	{
		if(A % 2 == 0)
		{
			contador++;
			A = A / 2;
		}
		else
		{
		 	A = (A*3)+1;
		 	//Se A for menor que o limite, então somamos ao contador.
			if(A <= L) contador++;
			else A = 1;		
		}
	}
	return 0;
}


int main()
{	

	int casos = 0;
	while(ler_valores())
	{
		casos++;
		processo();
		printf("Case %d: A = %lli, limit = %lli, number of terms = %d\n", casos, B, L, contador);
		contador = 1;
		
	}
	system("PAUSE");
	return 0;
}

