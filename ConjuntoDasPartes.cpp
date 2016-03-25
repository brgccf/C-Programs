#include <stdio.h>

/*

Gerar o conjunto das partes de um conjunto A 
(os subconjuntos de A) iterativamente

*/

int A[] = {1, 1, 3, 1};

int main()
{
	int i, n, j, k, sum = 0;
	n = 4;
	for(i = 0; i < n; i++) sum += A[i];
	if(sum % 2)
	{
		printf("no\n");
		return 0;
	}
	for(i=0; i<(1<<n);i++) {
		int sum_test = 0;
		for(k=j=0;j<n;j++) if(i&(1<<j)) sum_test += A[j];
		if(sum_test == sum/2)
		{
			printf("yes\n");
			break;
		}
		
	}
	if(i == (1<<n)) printf("no\n");
	return 0;
}
