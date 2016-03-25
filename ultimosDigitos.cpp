//problema 3: quais os ultimos tres digitos do numero 7^1111111111111111111   (19 um's)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long A;
unsigned long long B;

unsigned long long aux_exp(unsigned long long A, unsigned long long B)
{
	int i;
	unsigned long long v, res;
	unsigned long long v1, med, v2;
	
	unsigned long long k = sqrt(B);
	
	// conseguindo A^k
	v = 1;
	for(i=0; i<k; i++) {
		if(i == B%k) v1 = v;
		v *= A;
		v %= 1000000000;
	}
	med = v;
	
	// conseguindo A^B
	v = 1;
	for(i=0; i<B/k; i++) {
		v *= med;
		v %= 1000000000;
	}
	v2 = v; 
	
	return (v1 * v2) % 1000000000;
}

unsigned long long our_exp(unsigned long long A, unsigned long long B)
{
	unsigned long long k = sqrt(B);
	unsigned long long v1 = aux_exp(A, B%k);
	unsigned long long v2 = aux_exp(A, k);
	unsigned long long v3 = aux_exp(v2, B/k);
	return (v3 * v1) % 1000000000;
}


int main()
{
	int A, B;
	scanf("%d %d",&A,&B);
	printf("resultado = %Lu\n", our_exp(A,B));
	return 0;
	
}
