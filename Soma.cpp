#include <stdio.h>

//problema: dados dois numeros a e b, imprimir a+b

int a,b;

int ler_dados()
{
	if(scanf("%d%d",&a,&b) != 2)  return 0;
	return 1;
}

void processo()
{
	printf("%d\n", a+b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freeopen ("soma.in", "r", stdin);
	freeopen ("soma.out", "w", stdout);
#endif

	while(ler_dados())
	{
		processo();
	}
	
	return 0;	
}
