#include "bits/stdc++.h"
#define max 100000
typedef struct dictio
{
	char word[10];
	char ref[10];
}dictio;

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

void print_nary()
{
	for (int i = 0; i < count; ++i)
	{
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	dictio nary[max];
	char msg[max];
	char line[21];
	int i = 0;
	while(1)
	{
		scanf("%s", &line);
		int total = strlen(line);
		for (i = 0; i < 10; ++i)
		{
			scanf("%c", &nary[i].word[i]);
			if(nary.word[i] == ' ') break;
		}
		for (i; i < total; ++i)
		{
			scanf("%c", &nary[i].ref[i]);
			
		}

		printf("%s\n", nary[i].word);
		printf("%s\n", nary[i].ref);


		break;
	}
	return 0;
}