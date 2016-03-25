#include <stdio.h>

int n;
int ast, hif;
/*
	a) P5 = *-*---*-*------------------------------*-*---*-*
	b) fazer programa que dado N imprime Pn (N < 20) - (1,5)
	c) imprimir a diferença entre o numero de caracteres '*' e ' ', em O(log N)
	onde N cabe em int, queremos apenas os últimos 5 digitos
	d) Dado i, achar o i-ézimo caractere de Pn em O(n); N < 20
	e) Dado N, achar quantos caracteres '*' tem em posições impares de Pn. 
	Aceito O(N*3^N), N < 30
*/

void read_data()
{
	scanf("%d", &n);
}

void spaces(int a)
{
	if(a == 1)
	{
		hif++;
		printf("-");
		return;
	}
	else{ 
		spaces(a-1);
		spaces(a-1);
		spaces(a-1);
	}
}

void write(int a)
{
	if(a == 1)
	{
		ast++;
		printf("*");
		return;
	}
	write(a-1);
	spaces(a-1);
	write(a-1);
}	

int main()
{
	ast = 0;
	hif = 0;
	read_data();
	write(n);
	int dif = ast - hif;
	printf("\ndifference = %d\n", dif);
	return 0;
}