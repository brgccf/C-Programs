#include <stdio.h>

int main()
{
	int i, n;
	scanf("%d", &n);
	for(i = 0;i < n+3; i++)
	{
		int s = (n*(n-1)/2 + 3*n + i)%10;
		printf("%d ", s );
	}
	printf("\n");
	return 0;
}
