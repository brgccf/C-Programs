#include <stdio.h>
//PROBLEMA AULA 11: Eh dado um array A de tamanho N
//retorne 'yes' se existem três elementos que somados dê resultado zero (pode repetir)

int n, a[1000000];

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	int i;
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	return 1;
}

void processa()
{
	
	int i, j, k;
	for(j=n-1;j>=1;j--) {
		for(i=0; i<j; i++) {
			if(a[i+1] < a[i]) {
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	
	for(k=0; k<n; k++) {
		i = 0; j = n-1;
		while(1) {
			if(i == n || j == -1) break;
			else if(a[i] + a[j] + a[k] < 0)  i++;
			else if(a[i] + a[j] + a[k] > 0) j--;
			else {
				printf("yes\n");
				return;
			}
		}
	}
	printf("no\n");
}


int main()
{
		
 	freopen ("in.txt","r",stdin);
 	freopen ("out.txt","w",stdout);

	while(ler_dados())
	{
		processa();
	}
	
	return 0;

}
