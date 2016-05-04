#include <stdio.h>
//dado um array A preenchido ordenadamente, diga o se o elemento N existe

unsigned int n;
unsigned int A[12] = {1, 3, 5, 6, 9, 10, 13, 16, 19, 21, 24, 34};

int search(int ini, int fim, int x)
{
	int mid = (ini + fim)/2;
	if(x == A[mid]) return mid;
	else if (ini >= fim) return -1;
	else if(x > A[mid]) search(mid+1, fim, x);
	else search(ini, mid-1, x);
}

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

int main()
{
	int result;
	while(ler_dados())
	{
		result = search(0, 11, n);
		if(result == -1) printf("Elemento nao existe!\n");
		else printf("elemento encontrado na posicao %d\n", result);
	}
		
	return 0;
}
