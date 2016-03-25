#include <stdio.h>
#include <stdlib.h>

int M, N;

int processo()
{
	int cortes = (M*N)-1;
	return cortes;
}

int main()
{
	while(scanf("%d%d", &M, &N) == 2)
	{
		int resultado = processo();
		printf("%d\n", resultado);
	}
	return 0;
}
