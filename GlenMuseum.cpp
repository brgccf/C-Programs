#include <stdio.h>
#define ULL unsigned long long

ULL n;

int read_data()
{
	scanf("%llu", &n);
	return 1;
}

void process(int count)
{
	if (n == 2 || (n%2) != 0)
	{
		printf("Case %d: 0\n", count);
		return;
	}

	ULL i = 3;
	ULL sum = 5, result = 1;

	while(1)
	{
		if(n == 4) break;
		result+=sum;
		sum+=i*i;
		i+=1;
		n-=2;
	}

	printf("Case %d: %llu\n", count, result);

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("GlenMuseum.in", "r", stdin);
	freopen("GlenMuseum.out", "w", stdout);
#endif
	int cnt = 1;
	while(read_data())
	{
		if(!n) break;
		process(cnt);
		cnt++;
	}
	return 0;
}