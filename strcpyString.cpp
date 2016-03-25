#include <stdio.h>

char A[1000];
char B[1000];

void strcpy(char stringA[], char stringB[])
{
	int i = 0;
	while(1)
	{
		if(stringB[i] == 0) break;
		i++;
	}
	char ch[i];
	int length = i;
	i = 0;
	while(1)
	{
		if(i == length) break;
		ch[i] = stringB[i];
		i++;
	}
	printf("resultado: %s", ch);
}

int main()
{
	scanf("%s", A);
	printf("A string A foi: %s\n", A);
	scanf("%s", B);
	printf("A string B foi: %s\n", B);
	strcpy(A, B);
	
	return 0;
}
