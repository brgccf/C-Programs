#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *s;
	char bonito[] = "bonito";
	s = bonito;
	printf(s);
	//free(s);
	//neste caso n�o ha necessidade do free, pois a memoria n�o foi alocada
	//pelo programador, e sim pelo compilador.
	return 0;
}

