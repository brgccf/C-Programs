#include <stdio.h>

/*
  Sao dados dois arrays ordenados de mesmo tamanho N: A e B
  Achar em O(log N) a mediana de A uniao B
*/

int n, a[1000000], b[1000000];

int ler_dados() {
	if(scanf("%d",&n) != 1) return 0;
	int i;
	for(i=0;i<n;i++) scanf("%d",a+i);
	for(i=0;i<n;i++) scanf("%d",b+i);
}

double meio(int l1, int r1, int l2, int r2) {
	int v[4];
	int k=0;
	while(1) {
		if(l1 == r1 && l2 == r2) return ((double) v[1] + v[2])/2;
		else if(l1 == r1) v[k++] = b[l2++];
		else if(l2 == r2) v[k++] = a[l1++];
		else if(a[l1] < b[l2]) v[k++] = a[l1++];
		else v[k++] = b[l2++];
	}
}

double mediana(int l1, int r1, int l2, int r2) {
	if(l1 + 1 == r1) return ((double) a[l1] + b[l2])/2;
	if(l1 + 2 == r1) return meio(l1,r1,l2,r2);
	int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
	if((r1-l1)%2) {
		if(a[m1] < b[m2]) return mediana(m1,r1,l2,m2+1);
		return mediana(l1,m1+1,m2,r2);
	} else {
		if(a[m1-1] < b[m2-1]) return mediana(m1-1,r1,l2,m2+1);
		else return mediana(l1,m1+1,m2-1,r2);
	}
}

void processa() {
	printf("mediana: %lf\n", mediana(0,n,0,n));
}

int main() {
	freopen ("problema2.in","r",stdin);
 	freopen ("problema2.out","w",stdout);
	while(ler_dados()) processa();
	return 0;
}