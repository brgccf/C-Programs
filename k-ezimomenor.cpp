#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PERM(x,y) {int t = (x); (x) = (y); (y) = t;}

/*
  Achar o k-ezimo menor elemento de um array dado
*/

int n, a[1000000];

int ler_dados() {
	if(scanf("%d",&n) != 1) return 0;
	int i;
	for(i=0;i<n;i++) scanf("%d",a+i);
}

// Novamente:
// Como ajeitar para ficar eficiente mesmo quando
// o array for cheio de elementos repetidos?
int quickselect(int l, int r, int key)
{
	if(l+1 >= r) return a[l];
	int p = l + rand()%(r-l);
	PERM(a[p],a[r-1]);
	int i, k;
	for(i=k=l;i<r-1;i++) {
		if(a[i] < a[r-1]) {
			PERM(a[i],a[k]);
			k++;
		}
	}
	PERM(a[r-1], a[k]);
	if(k == key) return a[k];
	else if(k > key) return quickselect(l,k,key);
	else return quickselect(k+1,r,key);
}

void processa() {
	printf("BEGIN\n");
	int ncasos, key;
	scanf("%d",&ncasos);
	while(ncasos--) {
		scanf("%d",&key);
		printf("%d\n",quickselect(0,n,key-1));
	}
	printf("END\n");
}

int main() {
	freopen ("problema3.in","r",stdin);
 	freopen ("problema3.out","w",stdout);
    srand(time(NULL));
	while(ler_dados()) processa();
	return 0;
}