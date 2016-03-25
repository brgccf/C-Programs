#include <stdio.h>
#define LL long long

LL m, n;

int read_data()
{
	if(scanf("%lld %lld", &m, &n) != 2) return 0;
	return 1;
}

LL process(LL n)
{
	if(n < 0) return 0;
	LL sum = 1;
	LL nmb10 = 1, nt = 0;
	while(n) {
		if(n%10 != 0) {
			sum += n/10*nmb10;
		} else {
			sum += (n/10-1)*nmb10 + (nt+1);
		}
		nt += n%10*nmb10;
		n /= 10, nmb10 *= 10;
	}
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("HowManyOs.in", "r", stdin);
	freopen("HowManyOs.out", "w", stdout);
#endif
	
	while(read_data())
	{
		if (m < 0 && n < 0) break;
		printf("%lld\n", process(n)-process(m-1));;
	}
	return 0;
}
