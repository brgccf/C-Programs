//www.cin.ufpe.br/~pmmc/if724/Aula15/problema_2.cpp
#include <stdio.h>

/*
     Considere a seq. S = 1, 1/2, (1/2)/(3/4), ((1/2)/(3/4))/((5/6)/(7/8)), 
                      ((1/2)/(3/4))/((5/6)/(7/8))/((9/10)/(11/12))/((13/14)/(15/16)), ...
     calcular o valor aproximado do n-ezimo elemento dessa sequencia
     (S_i com i -> infinito = sqrt(2)/2 ! =)
*/

int n;

int ler_dados() {
	return scanf("%d",&n) == 1;
}

double f(int a, int b)
{
	if(a == b) return a;
	return f(a, (a+b-1)/2)/f((a+b+1)/2, b);
}

int main() {
	if(ler_dados())
	{
		printf("f(%d) = %lf", n, f(1, 1 << n));
	}
	return 0;
}
