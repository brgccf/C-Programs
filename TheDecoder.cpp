#include <bits/stdc++.h>

char ch[10000];
int read_data()
{
	gets(ch);
	if(ch[0]) return 1;
	return 0;
}

void process()
{
	
	int limit = strlen(ch);
	int i;
	for(i = 0; i < limit; i++)
	{
		printf("%c", ch[i]-7);
	}
	printf("\n");
	
	ch[0] = 0;
}

int main()
{
	while(read_data())
	{
		process();
	}
	return 0;
}
