#include <stdio.h>
#define ULL unsigned long long


ULL n;


int read_data()
{
	if(scanf("%d", &n) != 1) return 0;
	return 1;
}

ULL combination(int n)
{
	//COMBINATION = ((n*(n-1)*(n-2))/3!)
	ULL mult = n*(n-1);
	mult *= (n-2);
    ULL comb = (mult/6);

    return comb;

}

ULL process()
{
	ULL next = 1;
	ULL i, result = 0;
	for(i = 3; i < n; i++)
	{
		if(i == n) break;
		ULL b = combination(i+1);
		result = next;
		next = b - next;
		
	}
	
	return result;
	
}

int main()
{
	ULL root;
	while(read_data())
	{
		if(n < 3) break;
		root = process();
		printf("Resultado: %llu\n", root);
	}
	
	return 0;
}

