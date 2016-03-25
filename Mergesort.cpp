#include <stdio.h>

/*
  Ordenar o array dado eficientemente
*/

int n, a[1000000], b[1000000];

int ler_dados() {
	if(scanf("%d",&n) != 1) return 0;
	int i;
	for(i=0;i<n;i++) scanf("%d",a+i);
}

void mergesort(int l, int r)
{
	if(l+1 == r) return;
	int m = (l+r)/2;
	mergesort(l,m);
	mergesort(m,r);
	int i=l, j=m, k=0;
	while(1)
	{
		if(i == m && j == r) break;
		else if(i == m) b[k++] = a[j++];
		else if(j == r) b[k++] = a[i++];
		else if(a[i] < a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	for(i=l;i<r;i++) a[i] = b[i-l];
}

void processa() {
	mergesort(0,n);
	int i;
	for(i=0; i<n; i++) printf("%d ",a[i]);
	printf("\n");
}

int main() {
	freopen ("problema1.in","r",stdin);
 	freopen ("problema1.out","w",stdout);
	while(ler_dados()) processa();
	return 0;
}