#include <stdio.h>
#define MAX 1000001
int primos[MAX];

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for( i = 2; i < MAX; i++) primos[i] = 1;
	for(i = 2; i <= 1000;i++) //O(n log n)
	{
		if(!primos[i]) continue;
		for(j = i+i; j < MAX; j+= i) primos[j] = 0;
	}
	int c = 0;
	for(i = 2; i < MAX; i++) //O(n^2 log n)
	{
		if(primos[i]) ++c;
		if(c == (n+1)*(n+1))
		{
			printf("%d\n", i);
			break;
		}
	}
	printf("\n");
	return 0;
}
