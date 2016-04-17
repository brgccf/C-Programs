#include "bits/stdc++.h"
#define ULL unsigned long long

ULL aux_exp(int A, int B)
{
	ULL i, res = 1, v = A;
	for(i = 0; (1<<i) < B; i++)
	{
		if(B & (1<<i))
		{
			res*=v;
			res %= 100000;
		}
		//printf("A^%d mod 100000 = %d\n", (1<<i), v);
		v *= v;
		v %= 100000;
	}
	
	printf("RES = %lld\n", res);
	
	return res;
	
}

int main(int argc, char const *argv[])
{
	int cases;
	scanf("%d", &cases);
	while(cases)
	{
		ULL numb_cases;
		scanf("%llu", &numb_cases);
		ULL array[numb_cases];
		int i;
		for (i = 0; i < numb_cases; ++i)
		{
			scanf("%llu", &array[i]);
			printf("array[%d] == %llu\n", i, array[i]);
		}
		
		

		
		--cases;
	}
	return 0;
}