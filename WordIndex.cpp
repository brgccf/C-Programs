#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
char line[6];
unsigned char seq[30];
char possibilities[MAX][6];
unsigned int count;
FILE *wifile;

int read_data()
{
	if (gets(line) != NULL)
	{
		return 1;
	}
	return 0;
}

int process()
{

	int i;
	//comparando palavra
	int achou = 0;
	for (i = 0; i < count; ++i)
	{
		if(!strcmp(possibilities[i], line))
		{
			achou = 1;
			break;
		}
	}
	if(!achou) return 0;
	return i+1;

}

void gerar(int j, int k, int i, int n)
{
	if(j == k) {
		for(i=0;i<k;i++) possibilities[count][i] = seq[i]+'a';
		count++;
		//printf("%c ",seq[i]+'A');
		// printf("\n"); 
		return;
	}
	for(;i<n;i++) {
		if(n+j < k+i) return; // melhorando a performance!
		seq[j] = i;
		gerar(j+1,k,i+1,n);
	}
}


int main()
{
	count = 0;
	int i;
	for (i = 1; i < 6; ++i)
	{
		gerar(0, i, 0, 26);
	}
	wifile = fopen ("WordIndex.in", "r");
#ifndef ONLINE_JUDGE
	freopen("WordIndex.in", "r", stdin);
	freopen("WordIndex.out", "w", stdout);
#endif	

	int res = 0;
	while(read_data())
	{
		res = process();
		printf("%d\n", res);
	}
	return 0;
}
