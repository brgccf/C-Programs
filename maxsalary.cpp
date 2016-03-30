#include <bits/stdc++.h>

int n;

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	int count = 1;
	while(n)
	{
		
		int tes[3];
		int i;
		for(i = 0; i != 3; ++i)
		{
			scanf("%d", &tes[i]);
		}
		int max = 0, min = 10001, mid = 0;
		for (int i = 0; i != 3; ++i)
		{
			if (tes[i] > max)
			{
				max = tes[i];
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			if (tes[i] < min)
			{
				min = tes[i];
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			if (tes[i] != max && tes[i] != min)
			{
				mid = tes[i];
			}
		}
		if (!mid)
		{
			if (tes[0] == tes[2] || tes[0] == tes[1])
			{
				mid = tes[0];
			}
		}
		
		printf("Case %d: %d\n", count, mid);
		++count;
		--n;
	}
	return 0;
}