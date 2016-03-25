#include <stdio.h>

char string[500];

int strlen(char string[])
{
	int i = 0;
	while(1)
	{
		if(string[i] == 0) break;
		i++;
	}
	int resultado = i;
	return resultado;
}

int main()
{
	
	scanf("%s", string);
	printf("A string lida foi: %s\n", string);
	printf("resultado = %d",strlen(string));
	return 0;
}
