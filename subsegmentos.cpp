#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int n, a[MAX];

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	int i;
	for(i = 0; i < n; i++) scanf ("%d", &a[i]);
	return 1;
}

void processo()
{
	int i, s = 0, max = 0;
	for(i = 0; i< n; i++)
	{
		s+= a[i];
		if(s < 0) 
		{
			s = 0;
			continue;
		}
		if(s > max) max = s;
	}
	printf("%d\n", max);

}

int main()
{
	while(ler_dados())
	{
		processo();
	}
	return 0;
}
