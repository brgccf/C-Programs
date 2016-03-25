#include <stdio.h>
/*
*

 *
***

  *
 ***
*****

   *
  ***
 *****
*******

...
*/

unsigned int n;

int ler_dados()
{
	if(scanf("%d", &n) != 1) return 0;
	else return 1;
}

void processo()
{
	int i, contador = 1, end = 1;
	int spaces, j = n;
	while(1)
	{
		for(spaces = j-1; spaces > 0; spaces--)
		{
			printf(" ");
		}
		for(i = 0; i < contador; i++)
		{
			printf("*");	
		}	
		printf("\n");
		if(end == n) break;
		end++;
		contador += 2;
		j--;
	}
}

int main()
{
	while(ler_dados())
	{
		processo();
	}
	return 0;
}
