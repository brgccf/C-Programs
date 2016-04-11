#include "bits/stdc++.h"

int n;

int main(int argc, char const *argv[])
{
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		int result[n];
		int limit = 5*n;
		int comb[limit], bool_res[limit];
		int i;
		for (i = 0; i < limit; ++i)
		{
			scanf("%d", &comb[i]);
			bool_res[i] = 0;
			
		}
		//sorting
		for (i = 0; i < n; ++i)
		{
			result[i] = 0;
		}
		i = 0;
		int aux;

		int interval = 5, st = 0;
		while(i < limit)
		{
			for (i = st; i < interval; ++i)
			{
				
				if(i >= limit) break;

				for (int j = i+1; j < interval; ++j)
				{
					if(comb[j] < comb[i])
					{
						aux = comb[i];
						comb[i] = comb[j];
						comb[j] = aux;
					}
				}
			}
			
			interval += 5;
			st += 5;
		}
		// printf("array:\n");
		// for (i = 0; i < limit; ++i)
		// {
		// 	printf("%d ", comb[i]);
		// }
		// printf("\n");
		//break;
		int count_eq = 0, cpr, cb, greater = 0;
		if(n > 1)
		{
			st = 0;
			for (i = 0; i < n; ++i)
			{
				for (int k = 0; k < 5; ++k)
				{
					cpr = comb[st+k];
					for (int h = k; h < limit; h+=5)
					{
						if(st+k == h) continue;
						cb = comb[h];
						if(cpr == cb) ++bool_res[h];
					}
				}
				st += 5;
			}	
			interval = 5;
			st = 0;
			int eq; 
			for (i = 0; i < n; ++i)
			{
				eq = 1;
				for (int m = st; m < interval; ++m)
				{
					if(!bool_res[m]) eq = 0;
				}
				if(eq) result[i] = bool_res[i+st];
				st += 5;
				interval += 5;
			}

			//verificando qual a posicao com maior valor dos resultados
			for (i = 0; i < n; ++i)
			{
				if(result[i] > greater) greater = i;
				//printf("result[%d] = %d\n", i, result[i]);
			}
			printf("%d\n", result[greater]);
		}

		else{
			printf("1\n");
		}
		
		

	}
	return 0;
}