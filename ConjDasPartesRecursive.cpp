#include <stdio.h>

/*

Gerar o conjunto das partes de um conjunto A 
(os subconjuntos de A) recursivamente

*/

char conj[30];
int k;

void gerar(int i, int n)
{
	if(i == n) {
		for(i=0;i<k;i++) printf("%c ",conj[i]);
		if(!k) printf("EMPTY"); 
		printf("\n"); return;
	}
	gerar(i+1,n);
	conj[k++] = i+'A';
	gerar(i+1,n);
	--k;
}

int main()
{
	int n;
	scanf("%d",&n);
	gerar(k=0,n);
	return 0;
}
