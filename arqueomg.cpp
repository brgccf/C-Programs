#include "bits/stdc++.h"

int main(int argc, char const *argv[])
{
	int cases, a, b;
	scanf("%d", &cases);
	while(cases)
	{
		scanf("%d%d", &a, &b);
		if(a > 0 && b > 0)
		{
			printf("%d\n", b-a);
		}
		else if(a < 0 && b > 0)
		{
			printf("%d\n", b-a-1);
		}
		else{
			printf("%d\n", (a-b)*-1);
		}

		--cases;
	}
	return 0;
}