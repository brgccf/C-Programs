#include <stdio.h>

int v, t;

int read_data()
{
	if(scanf("%d%d", &v, &t) != 2) return 0;
	return 1;
}

int main()
{
	while(read_data())
	{
		printf("%d\n", v*t*2);
	}
	return 0;
}
