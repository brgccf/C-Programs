#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define LL long long
#define MAX 1000000000
unsigned char eh_primo[MAX];

int main() {
	LL cases, m, n;
	scanf("%lld", &cases);
	memset(eh_primo, 1, MAX);
	LL last_n = 2;
	while(cases)
	{
		scanf("%lld%lld", &m, &n);
		//prime_to_n(m, n);
		LL i, j;
		if(m ==1) ++m;
		
		for(i = 2; i <= n; i++)
		{
			if(eh_primo[i])
			{
				for(j = i+i; j <= n; j+=i)
					eh_primo[j] = 0;
			}
		}
		for(i = m; i <= n ; i++) if(eh_primo[i]) printf("%d\n", i);
		if(cases!= 1)printf("\n");
		--cases;
		
	}
	
	return 0;
}
