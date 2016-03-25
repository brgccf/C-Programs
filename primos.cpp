#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000000
#define __EASY_MODE__
//#define __MEDIUM_MODE__
//#define __HARD_MODE__
//#define __VERY_HARD_MODE__
unsigned char eh_primo[MAX];

#ifdef __EASY_MODE__
void prime_to_n(int n) 
{
	// n²
	int i, j;
	for(i=2; i<=n; i++) {
		for(j=2; j<i; j++) {
			if(i % j == 0) break;
		}
		if(i == j) printf(" %d",i);
	}
	printf("\n");
}
#else
#ifdef __MEDIUM_MODE__
void prime_to_n(int n)
{
	// n * raiz de n
	int i, j;
	for(i=2; i<=n; i++) {
		int lim = ((int) sqrt(i)) + 1;
		for(j=2; j<lim; j++) {
			if(i % j == 0) break;
		}
		if(j == lim) printf(" %d",i);
	}
	printf("\n");
}

#else
#ifdef __HARD_MODE__
void prime_to_n(int n)
{
	//vamos utilizar o array global
	//o array designará por 0 ou 1 se o numero for primo ou não
	//de inicio, consideramos que todos os numeros sao primos
	int i, j;
	for(i = 2; i <= n; i++) eh_primo[i] = 1;
	for(i = 2; i <= n; i++)
	{
		for(j = i+i; j <= n; j+=i)
			eh_primo[j] = 0;
	}
	for(i = 2; i <= n ; i++) if(eh_primo[i]) printf("%d ", i);
	printf("\n");
	// eficiencia: O (nlog(n))
	
}
#else __VERY_HARD_MODE__
void prime_to_n(int n)
{
	int i, j;
	for(i = 2; i <= n; i++) eh_primo[i] = 1;
	for(i = 2; i <= n; i++)
	{
		if(eh_primo)
		{
			for(j = i+i; j <= n; j+=i)
				eh_primo[j] = 0;
		}
	}
	for(i = 2; i <= n ; i++) if(eh_primo[i]) printf("%d ", i);
	printf("\n");
}
//eficiencia O(nlog(log(n)))
#endif
#endif
#endif

int main() {
	
	int n = 1000000;
	
	prime_to_n(n);
	
	return 0;
}
