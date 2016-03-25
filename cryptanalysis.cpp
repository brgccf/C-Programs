#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#define PERM(x,y) {int __t__ = (x); (x) = (y); (y) = __t__;}
unsigned int total_casos;
std::string texto_lido;
unsigned int repeat[26];


int ler_total_casos()
{
	if(scanf("%d", &total_casos) != 1) return 0;
	else return 1;
}

void ler_texto()
{
	char c;
	std::string ler;
	total_casos++;
	while(total_casos)
	{
		std::getline(std::cin,ler);
		total_casos--;
		texto_lido.append(ler);
		//std::cout << "\nSituação atual do texto lido: " << texto_lido << '\n';
	}
 	//std::cout << "\nSituação FINAL do texto lido: " << texto_lido << '\n';
}

void processo()
{
	int i;
	int limite = texto_lido.size();
	for(i = 0; i < limite; i++)
	{
		if(texto_lido[i] >= 'a' && texto_lido[i] <= 'z')
		{
			repeat[texto_lido[i]-'a']++;
		}
		else if(texto_lido[i] >= 'A' && texto_lido[i] <= 'Z')
		{
			repeat[texto_lido[i]-'A']++;
		}
	}
	unsigned int aux[26];
	for(i = 0; i < 26; i++)
	{
		aux[i] = repeat[i];
	}
	//reorganiza o array aux para encontrar o valor que mais se repete
	int j, k;
	for(j = 0; j < 26; j++)
	{
		for(i = 0; i < 26; i++)
		{
			if(aux[i] < aux[j]) PERM(aux[i], aux[j]);
		}
	}
	unsigned int maior = aux[0];
	
	//imprimindo
	for(j = maior; j > 0; j--)
	{
		for(k = 0; k < 26; k++)
		{
			if((repeat[k] == j))
			{
				printf("%c %d\n", k+65, repeat[k]);
			}
		}
	}
	
}

int main()
{
	/*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
*/


	int i;
	for(i = 0; i < 26; i++) repeat[i] = 0;
	if(ler_total_casos()) ler_texto();
	processo();
	
	return 0;
}
