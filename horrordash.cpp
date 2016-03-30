#include <bits/stdc++.h>

int n, cases;

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	int count = 1;
	while(n)
	{
		scanf("%d", &cases);
		int tes[cases];
		int i;
		for(i = 0; i != cases; ++i)
		{
			scanf("%d", &tes[i]);
		}
		int temp = 0;
		for (int i = 0; i != cases; ++i)
		{
			if (tes[i] > temp)
			{
				temp = tes[i];
			}
		}
		
		printf("Case %d: %d\n", count, temp);
		++count;
		--n;
	}
	return 0;
}