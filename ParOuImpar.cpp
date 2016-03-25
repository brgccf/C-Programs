#include <stdio.h>

int eh_par(int n)
{
	if(n == 0) return 1;
	else if(n == 1) return 0;
	if(eh_impar(n-1)) return 1;
	else return 0;
}

int eh_impar(int n)
{
	if (n == 1) return 1;
	else if(n == 0) return 0;
	if(eh_par(n-1)) return 1;
	else return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(eh_par(n)) printf("eh par");
	else if (eh_impar(n))printf("eh impar");
	return 0;
}
