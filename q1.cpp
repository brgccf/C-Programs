#include "bits/stdc++.h"
int m, n;

int main(int argc, char const *argv[])
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int ar[n];
		for(int i = 0 ; i < n; i++)
		{
			scanf("%d", &ar[i]);
		}
		int k, v;
		for(m; m > 0; m--)
		{
			int count = 0;
			scanf("%d%d", &k, &v);
			for (int i = 0; i < n; ++i)
			{
				if(k && (ar[i]==v))
				{
					count = i;
					--k;
				}
				else if(!k) break;
			}
			if(k) printf("0\n");
			else printf("%d\n", count+1);
		}
	}
	return 0;
}