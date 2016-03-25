#include <stdio.h>

int A[] = {7, 1, 1, 1, 1, 1, 1, 7};
//verificar se há dois subconjuntos em que a soma de todos os elementos deles
//sejam equivalentes. 
//basicamente precisamos somar todos os elementos do original e dividir por 2. 
//dai formamos subconjuntos e verificamos se a soma dá o total do original dividido por 2.
//se isso for possivel, então a propriedade é verdadeira.

int generate(int i, int n, int s, int obj)
{
	if(s == obj) return 1;
	if(s > obj) return 0; //se a soma ja tiver ultrapassado (faz um corte e pode ser mais eficiente)
	if(i == n) return 0; //significa que chegou ao final
	if(generate(i=1, n, s, obj)) return 1;
	s += A[i];
	if(generate(i+1, n, s, obj)) return 1;
	return 0;
}

int main()
{
	int i, n = 8, sum_total = 0;
	for(i = 0; i < n; i++) sum_total += A[i];
	if(sum_total & 1) 
	{
		printf("no\n");
	}
	else if (generate(0, n, 0, sum_total/2)) printf("yes\n");
	else printf("no\n");
	return 0;
	 
	
	return 0;
}
