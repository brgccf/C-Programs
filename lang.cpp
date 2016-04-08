#include <bits/stdc++.h>


char lang[15];

int main(int argc, char const *argv[])
{
	int cases = 1;
	while(1)
	{
		scanf("%s", &lang);
		if (!strcmp(lang, "#"))break;
		if(!strcmp(lang,"HELLO")) printf("Case %d: ENGLISH\n", cases);
		else if(!strcmp(lang,"HOLA"))
			printf("Case %d: SPANISH\n", cases);
		else if(!strcmp(lang,"HALLO"))printf("Case %d: GERMAN\n", cases);

		else if(!strcmp(lang,"BONJOUR"))printf("Case %d: FRENCH\n", cases);
		else if(!strcmp(lang,"CIAO"))printf("Case %d: ITALIAN\n", cases);

		else if(!strcmp(lang,"ZDRAVSTVUJTE"))printf("Case %d: RUSSIAN\n", cases);
		else printf("Case %d: UNKNOWN\n", cases);
		++cases;
	}
	return 0;
}