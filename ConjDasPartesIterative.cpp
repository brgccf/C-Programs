#include <stdio.h>

/*

Gerar o conjunto das partes de um conjunto A 
(os subconjuntos de A) iterativamente

*/

int main()
{
	int i, n, j, k;
	char conj[30];
	scanf("%d",&n);
	for(i=0; i<(1<<n);i++) {
		for(k=j=0;j<n;j++) if(i&(1<<j)) conj[k++] = 'A'+j;
		for(j=0;j<k;j++) printf("%c ",conj[j]);
		if(!k) printf("EMPTY");
		printf("\n");
	}
	return 0;
}
