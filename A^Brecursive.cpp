#include <stdio.h>
//fazer A^B recursivamente

unsigned long A, B;

unsigned long long exp(unsigned long A, unsigned long B)
{
	if(B == 1) return A;
	else return A*exp(A, B-1)%1000000000;
}

int exp_2(int a, int b)
{
	if(b == 0) return 1;
	int x = exp(a, b/2);
	if(b%2) return a *x * x;
	return x*x;
}

int main()
{
	scanf("%d%d", &A, &B);
	printf("Result: %Lu", exp_2(A,B));
	return 0;	
}
