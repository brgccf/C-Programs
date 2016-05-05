#include "stdio.h"
int main()
{
	int n, resultado;
	printf("Digite n:\n");
	scanf("%d", &n);
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
	while(n > 0)
	{
		scanf("%d", &resultado);
		switch(resultado)
		{
			case(1):
				++f1;
				break;
			case(2):
				++f2;
				break;
		}
		--n;
	}
	//fazer print para cada face!
	return 0;
}

