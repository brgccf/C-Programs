#include <stdio.h>

int n;

int read_data()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

void process()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	while(read_data())
	{
		process();
	}
	
	return 0;
}


