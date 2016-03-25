#include <stdio.h>
//dado n imprima a menor montanha possivel
int main()
{
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("/");
		printf("\\");
	}
	printf("\n");
	int j, spaces = 0, k = n-1;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < k; j++) printf(" ");
		for(j = k; j > 0; j--)
		{
			printf("/");
			if(spaces) printf(" ");
			printf("\\");
		}
		k -= 1;
		printf("\n");
		spaces++;
	}
	return 0;
}
/*

  /\ 
 /  \
/    \

*/
