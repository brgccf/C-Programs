#include <stdio.h>

/*

Problema: 

Eh dado um mapa (N por M) inicialmente como esse abaixo.

012345678901234567          
1......./..\.....
2.............\..
3.......\.......\
4................
5...\.........\./
6..........\../..
7................
8
                 
(N = 7, M = 16)

Os '\' e '/' sao refletores.

Se um raio laser for usado verticalmente ou horizontalmente
(conforme fizer sentido) a partir de uma extrmidade da matriz,
ele vai atingir uma outra extremidade T.

O problema eh descobrir, para cada S, quem eh T. As coordenadas
comecam do 0. Os refletores nunca terao coordenadas 0.
O mapa compreende a regiao [1..N] X [1..M]

No exemplo abaixo: S = (0,4) e T = (2,0)

    S
 ...0.../10\.....
T.09*765*32*10\..
 ...2...\01*34*6\
 ...3......1..0.0
 ...\012345*78\0/
 ..........\10/..
 ................

No exemplo abaixo: S = (8,4) e T = (5,0)


 ......./..\.....
 .............\..
 .......\.......\
 ................
T210\.........\./
 ...1......\../..
 ...0............
    S

tamanho maximo do tabuleiro = 50 x 50
(algoritmo recursivo -> perigo de stackoverflow!)

Vou apresentar o algoritmo abaixo que tem custo O(NM(N+M)).
Tem como fazer melhor no pior caso em funcao de N e M?

*/

char mapa[50+2][50+2];
int n, m;
 
/* 0 => /, 1 => \
*/
int ler_mapa()
{
	if(scanf("%d%d",&n,&m) != 2) return 0;
	/*
	int i, j;
	for(i=1;i<=n;i++)      
		scanf("%s", &mapa[i]+1);
	*/ 
	return 1;         
}

void movement_right(int i, int j);
void movement_left(int i, int j);
void movement_up(int i, int j);
void movement_down(int i, int j)
{
	printf("(%d, %d) = ", i, j);
	while(1)
	{	
		if(i == n) break;
		if(mapa[i][j] == '/') movement_left(i, j);
		if(mapa[i][j] == '\\') movement_right(i , j); 
		i++;
 	}
 	printf("(%d, %d)\n", i, j);
}

void movement_left(int i, int j)
{
	printf("(%d, %d) = ", i, j);
	while(1)
	{	
		if(j == -1) break;
		if(mapa[i][j] == '/') movement_down(i, j);
		if(mapa[i][j] == '\\') movement_up(i , j); 
		j--;
 	}
 	printf("(%d, %d)\n", i, j+1);
}

void movement_right(int i, int j)
{
	printf("(%d, %d) = ", i, j);
	while(1)
	{	
		if(j == m) break;
		if(mapa[i][j] == '/') movement_up(i, j);
		if(mapa[i][j] == '\\') movement_down(i , j); 
		j++;
 	}
	printf("(%d, %d)\n", i, j);
}

void movement_up(int i, int j)
{
	printf("(%d, %d) = ", i, j);
	while(1)
	{	
		if(i == -1) break;
		if(mapa[i][j] == '/') movement_right(i, j);
		if(mapa[i][j] == '\\') movement_left(i , j); 
		i--;
 	}
 	printf("(%d, %d)\n", i+1, j);
}

void processa()
{
	int i, j;
	printf("BEGIN\n");
	//parte superior
	i = 0; 
	for(j = 1; j < m; j++) movement_down(i, j);
	//coluna da esquerda
	j = 0;
	for(i = 1; i < n; i++) movement_right(i, j);
	//parte inferior
	i = n;
	for(j = 1; j < m; j++) movement_up(i, j);
	//coluna da direita
	j = m;
	for(i = 1; i < n; i++) movement_left(i, j);
	
	printf("END\n\n");
}

int main() 
{
	printf("===LEITURA DE ARQUIVO...===\n");
 	freopen ("in.txt","r",stdin);
 	freopen ("out.txt","w",stdout);
	unsigned int cases = 1;
	while(ler_mapa())
	{
		int i, j;
	for(i=0;i<n;i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%c", &mapa[i][j]);	
		}
	}      
		printf("===MAPA LIDO:===");
		for(i = 0; i < 7; i++)
		{
			for(j = 0; j < 16; j++)
			{
				printf("%c", mapa[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("=====CASO %d:=====\n", cases);
		processa();
		cases++;
	}
	
	return 0;
}
