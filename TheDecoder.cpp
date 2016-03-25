#include <stdio.h>
#include <string.h>



char ch[10000];
int read_data()
{
	gets(ch);
	if(ch[0]) return 1;
	return 0;
}

void process()
{
	/*char c = ch-7;
	if(c > 3)printf("%c", c);
	if(c == '.')
	{
		printf("\n");
	}
	*/
	int limit = strlen(ch);
	int i;
	for(i = 0; i < limit; i++)
	{
		printf("%c", ch[i]-7);
	}
	printf("\n");
	
	
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(read_data())
	{
		process();
	}
	return 0;
}
