#include <bits/stdc++.h>
#define LL long long

LL z, i, m, L;

int main(int argc, char const *argv[])
{
	int cases = 1, result = 0;
	LL res = 0, temp;
	while(1)
	{
		scanf("%lld%lld%lld%lld", &z, &i, &m, &L);
		if(z == 0 && i == 0 && m == 0 && L == 0) break;
		int count = 0;
		
		while(res != L)
		{
			if(count == 1)L = res;
			res = ((z*temp)+i)%m;

			//printf("res = %lld\n", res);
			temp = res;
			++result;
			//printf("result = %d\n", result);
			if(!res)break;
			++count;
			

		}
		if(!res)--result;
		printf("Case %d: %lld\n", cases, result);
		++cases;
		result = 0;

	}
	return 0;
}