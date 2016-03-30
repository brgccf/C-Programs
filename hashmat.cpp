#include <bits/stdc++.h>

int a, b;

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(scanf("%d%d", &a, &b) != EOF)
	{
		if(a > b) printf("%d\n", a-b);
		else printf("%d\n", b-a);
	}
	return 0;
}