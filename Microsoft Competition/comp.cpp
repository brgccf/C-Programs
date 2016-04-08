#include <bits/stdc++.h>

int res[500];

int main(int argc, char const *argv[])
{
	memset(res, -1, 500);
	int n;
	while(scanf("%d", &n) == 1)
	{
		int i, j = 0, sum = 0, unit = 0, mult;
		res[j] = n;
		int limit = n*10;
		for (i = 10; i < limit; i*=10)
		{
			int comp = n;
			if (n < 10)
			{
				unit = n;
			}
			else while (comp > 10) comp /= 10;
			if (!unit)
			{
				mult = comp;
				printf("mult antes = %d\n", mult);
				mult *= mult;
				printf("mult depois = %d\n", mult);

			}
			else
			{
				mult = unit;
				printf("mult antes = %d\n", mult);
				mult *= mult;
				printf("mult depois = %d\n", mult);
			}
			sum+= mult;

			if (i > n)
			{
				++j;
				res[j] = sum;
				printf("atualizando array com: %d\n", res[j]);
			}
			printf("n = %d\n", n);
			if (n < 100)
			{
				n %= 10;
			}
			else n /= 10;
			printf("n depois = %d\n", n);
			int found = 0;
			printf("res[j] = %d\n", res[j]);
			if (res[j] == 1) break;
			// else 
			// {
			// 	int k, key;
			// 	for (i = 0; i <= j; ++i)
			// 	{
			// 		for (k = i+1; k < j; ++k)
			// 		{
			// 			if (res[i] == res[k])
			// 			{
			// 				printf("===entrou no if \n");
			// 				found = 1;
			// 				key = res[i];
			// 			}
			// 		}
			// 		if (found) break;
			// 	}
			// }
			if(found) break;
			else
			{
				n = res[j];
				i = 10;
			}
		}
		printf("===saiu do for principal===\n");
	}
	return 0;
}