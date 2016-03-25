#include <stdio.h>

int m[128][128];

void atribuir(int n, int i, int j, int k)
{
	if(n == 0) m[i][j] = k;
	else {
		//2 elevado a (n-1) == c
		int c = 1 << (n-1);
		//as chamadas abaixo estao em ordem dos quadrantes
		atribuir(n-1,i,j,k);
		atribuir(n-1,i,j + c, k + c*c);
		atribuir(n-1,i + c,j, k + 2*c*c);
		atribuir(n-1,i + c,j + c, k + 3*c*c);
	}
}

void diagonal(int n, int i, int j, int k)
{
	if(n == 0) printf("%4d", k);
	else
	{
		int c = 1 << (n-1);
		diagonal(n-1, i, j, k);
		diagonal(n-1, i + c, j + c, k + 3*c*c);	
	}
}

void coordenates(int n, int i, int j, int k, int key)
{
	if(k == key){
		printf("(%3d, %3d)\n", i+1, j+1);
	}	
	else if (n==0) return;
	else
	{
		int c = 1 << (n-1);
		if(key < k + c*c)coordenates(n-1, i, j, k, key);
		else if (key < k + 2*c*c) coordenates(n-1, i, j + c, k + c*c, key);
		else if (key < k + 3*c*c) coordenates(n-1, i + c, j, k + 2*c*c, key);
		else coordenates(n-1, i + c, j + c, k + 3*c*c, key);
	}
	
}

int main()
{
	int i, j, key, n;
	scanf("%d",&n);
	//coordenates(10, 0, 0, 1, key);
	//o 1 abaixo é o valor que a matriz inicia (a11)
	//diagonal(n,0,0,1);
	atribuir(n, 0, 0, 1);
	for(i=0;i<(1<<n);i++) {
		for(j=0;j<(1<<n);j++)
			printf("%4d",m[i][j]);
		printf("\n");
	}
	
	return 0;
}
