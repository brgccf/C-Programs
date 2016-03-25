#include <stdio.h>

/*

Gerar todas as subsequencias de uma sequencia A
de tamanho k

*/

unsigned char seq[30];

void gerar(int j, int k, int i, int n)
{
	if(j == k) {
		for(i=0;i<k;i++) printf("%c ",seq[i]+'A');
		printf("\n"); 
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
	int k,n;
	scanf("%d%d",&n,&k);
	gerar(0,k,0,n);
	return 0;
}