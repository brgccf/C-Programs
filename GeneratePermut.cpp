#include <stdio.h>

/*

Gerar as permutacoes de A (n!)

*/

unsigned char seq[30];
unsigned char mark[30]; //array auxiliar que marca elementos, para evitar utiliza-los novamente

void gerar(int i, int n)
{
	if(i == n) {
		for(i=0;i<n;i++)
		{
			printf("%c ",seq[i]+'A');
		} 
		printf("\n"); return;
	}
	int j;
	for(j=0;j<n;j++) {
		if(mark[j]) continue; //se ja tiver marcado prossegue no algoritmo
		/*
		if(mark[1] && j == 0) continue; //colocando restriçoes de permutacoes
		if(mark[3] && j == 0) continue;
		if(mark[2] && j == 5) continue;
		if(mark[1] && j == 4) continue;
		*/
		mark[seq[i] = j] = 1;
		gerar(i+1,n);
		mark[j] = 0; //desmarca o elemento apos o uso
	}
}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) mark[i] = 0;
	gerar(0,n);
	return 0;
}
