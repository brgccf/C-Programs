#include <stdio.h>
//O(n)
int soma_pg(int n)
{
	if(n == 0) return 1;
	return (soma_pg(n-1) << 1) + 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("Result: %d", soma_pg(n));
	return 0;
}
