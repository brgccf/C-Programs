#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r", stdin);
	freopen("out.txt","w", stdout);
#endif
	char n;
	int ativo = 0;
	while(scanf("%c", &n)!=EOF)
	{
		if(n == '"')
		{
			if(ativo)
			{
				printf("%c", '\'');
				printf("%c", '\'');
				ativo = 0;
			}
			else
			{
				printf("%c", '`');
				printf("%c", '`');
				ativo += 1;
			}
		}
		else
		{
			printf("%c", n);
		}
	}
	return 0;
}
