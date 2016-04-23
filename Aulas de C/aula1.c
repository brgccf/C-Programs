#include "stdio.h"

int main()
{
	float n, qtd_paises, ouro, prata, bronze;
	scanf("%d", &n);
	char paises[n][2];
	int regioes[n];
	float cont = 0;
	for(n; n > 0; n--)
	{
		scanf("%f", &qtd_paises);

		while(qtd_paises > 0)
		{
			scanf("%c", &paises[cont][0]);
			scanf("%c", &paises[cont][1]);

			scanf("%f", ouro);
			scanf("%f", prata);
			scanf("%f", bronze);



			qtd_paises--;
			cont++;
		}
	}
	
	return 0;
}