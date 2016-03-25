#include <stdio.h>
#include <stdlib.h>
//matriz n x m
unsigned int m, n;
unsigned char mapa[100][100+1];
unsigned char mark[100][100+1];
//variavel global para contar muros quebrados
unsigned nmbwalls = 0;
//baixo, cima, direita, esquerda
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

//coordenadas das casas
typedef struct coordenates
{
	int x;
	int y;
} Coord;
	

int ler_mapa()
{
	//linhas = n; colunas = m
	if(scanf("%d%d",&n,&m) != 2) return 0;
	int i;
	for(i=0;i<n;i++)      
		scanf("%s", mapa[i]); 
	return 1;         
}

//DFS == busca em produndidade == Fail
void DFS(int i, int j, int nm);

//Busca em largura
//i e j sao a posicao do S
void BFS(int i, int j)
{
	//utilizará o mapa lido e um array para marcar os passos dados (mark)
	//marca todos os vertices como nao visitados:
	int k, z;
	for(k = 0; k < n; k++)
	{
		for(z = 0; z < m; z++)
		{
			mark[k][z] = 0;
		}
	}
	int total_casas = n*m; //total de possibilidades (?)
	
	
	//marca a posicao inicial
	mark[i][j] = 1;
	while(1)
	{
		//int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		//down, up, right, left
		//...
		
		//??
		
	}
	
}

void process()
{
	int i, j;
	printf("Mapa Lido:\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%c", mapa[i][j]);
		}
		printf("\n");
	}
	int a, b;
	
	//procurando S...
	printf("=====Procurando S...======\n");
	unsigned int achou = 0;

	
	Coord pos_s;
	Coord pos_t;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(mapa[i][j] == 'S')
			{
				achou++;
				pos_s.x = i;
				pos_s.y = j;
			}
			if(mapa[i][j] == 'T')
			{
				achou++;
				pos_t.x = i;
				pos_t.y = j;
			}
		}
		if(achou == 2) break;
	}
	printf("S está na posicao: (%d, %d)\n", pos_s.x, pos_s.y);
	printf("T esta na posicao: (%d, %d)\n", pos_t.x, pos_t.y);
	
	
	//DFS(pos_s.x, pos_s.y, nmbwalls);
	
	
		
}

//Busca em profundidade
void DFS(int i, int j, int nm)
{
	unsigned int achou_T = 0;
	if(i < 0 || j < 0 || i == n || j == m) return;
	if(achou_T) return;
	if(mapa[i][j] == '#')
	{
		printf("achou um muro em: (%2d, %2d)\n", i, j);
		nmbwalls++;
	}
	if(mapa[i][j] == 'T')
	{
		printf("T esta em: (%2d, %2d)\n", i, j);
		achou_T = 1;
		return;
	}
	if(mapa[i][j] == 'o') return;
	mapa[i][j] = 'o';
	int z, w;
	printf("=== MAPA PARCIAL ===\n");
	for(z = 0; z < n; z++)
	{
		for(w = 0; w < m; w++)
		{
			printf("%c", mapa[z][w]);
		}
		printf("\n");
	}
	nm = nmbwalls;
	
	int k;
	for(k = 0; k < 4; k++) DFS(i+dir[k][0], j+dir[k][1], nm);
}

int main()
{
	int i, j;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	while(ler_mapa())
	{
		process();
	}
	printf("==== MAPA FINAL ======\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%c", mapa[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}
