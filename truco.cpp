#include <bits/stdc++.h>

int a, b;

int main(int argc, char const *argv[])
{
	while(scanf("%d%d", &a, &b) == 2){
		if (a > b)
		{
			printf("%d\n", a);
		}
		else if (b > a)
		{
			printf("%d\n", b);
		}
		else printf("%d\n", a);
	}
	return 0;
}