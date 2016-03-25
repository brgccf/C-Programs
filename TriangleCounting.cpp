#include <stdio.h>
#define MILHAO 10000000
#define ULL unsigned long long


ULL n;


int read_data()
{
	if(scanf("%d", &n) != 1) return 0;
	return 1;
}


ULL process()
{
	if(n == 3) return 0;
	ULL sum = 0, result = 0;
	ULL isTwo = 1, count = 1;
	while(1)
	{
		sum += count;
		if(isTwo == 2)
		{
				isTwo = 0;
				count++;
		}
		isTwo++;
		n--;
		result += sum;
		if(n == 3)break;
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
		printf("%llu\n", root);
	}
	
	return 0;
}

