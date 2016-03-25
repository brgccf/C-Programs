#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *s;
	char bonito[] = "bonito";
	s = bonito;
	printf(s);
	//free(s);
	//neste caso não ha necessidade do free, pois a memoria não foi alocada
	//pelo programador, e sim pelo compilador.
	return 0;
}

