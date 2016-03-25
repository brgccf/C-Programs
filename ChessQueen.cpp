#include <stdio.h>
#define ULL unsigned long long
unsigned long long m, n;

int read_data()
{
	if(scanf("%llu %llu", &m, &n) != 2) return 0;
	if(m & n == 0) return 0;
	return 1;
}

unsigned long long process()
{
	//calculating lines possibilities...
	ULL lines = n*(n-1)*m;
	//calculating columns possibilities...
	ULL columns = m*(m-1)*n;
	//calculating diagonal... n - (m-1)
	ULL diag = 0;
	if(m > n)
	{
		ULL aux = n;
		n = m;
		m = aux;
	}
	//encontrando qtd de diagonais tamanho m:
	ULL diag_m = n - (m - 1);
	//calculando possibilidades para diagonais de tamanho m:
	ULL pos_diag_m = m*(m-1)*diag_m;
	pos_diag_m *= 2; // multiplica por 2
	diag += pos_diag_m;
	//encontrando diagonais restantes:
	m--;
	while(m > 1)
	{
		diag += m*(m-1)*4; //4 pois tem diagonal principal e secundaria
		m--;
	}
	
	ULL sum = lines + columns + diag;
	return sum;
}

int main()
{
	
	unsigned long long result;
	while(read_data())
	{
		if(m != 0 && n != 0)
		{
			result = process();
			printf("%llu\n", result);
		}
	}
	
	return 0;
}
