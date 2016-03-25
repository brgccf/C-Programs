#include <stdio.h>

char dia_da_semana[7][20] = {"domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};
//7 dias da semana, 20 máximo de caracteres
int main()
{
	int n;
	scanf("%d", &n);
	n %= 7;
	printf ("%s", dia_da_semana[n]);
	return 0;
}
