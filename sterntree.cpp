#include <bits/stdc++.h>

long long a, b, c, d, m, n;

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	while(N)
	{
		a = 0, b = 1;
		c = 0, d = 1;
		m = a + b;
		n = c + d;
		int i;
		char read[91];
		scanf("%s", read);
		for (i = 0; read[i]; ++i)
		{

			if (read[i] == 'R')
			{
				a = m;
				m = a + b;
				d = n;
				n = c + d;
			}
			if (read[i] == 'L')
			{
				b = m;
				m = a + b;
				c = n;
				n = c + d;
			}
		}

		printf("%lld/%lld\n", m, n);
		--N;
	}
	return 0;
}