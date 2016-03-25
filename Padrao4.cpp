#include <stdio.h>

int n;
int limit;
unsigned int spaces = 0;
unsigned int stop = 1;

int read_data()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

void process()
{
	int i, j;
	j = 1;
	limit = (2*n)-1;
	int k = limit - 1 + spaces;
	while(1)
	{
		for(i = 0; i < k/2; i++)
		{
			printf(" ");
		}
		for(i = 0; i < j; i++)
		{
			printf("*");
		}
		printf("\n");
		j+=2;
		k-=2;
		if(j > limit) break;
	}
}

int main()
{

	while(read_data())	
	{
	
		while(n > 0 && stop)
		{
			process();
			n--;
			spaces+=2;
		}
		spaces = 0;
		stop = 1;
		
	}
	return 0;	
}

