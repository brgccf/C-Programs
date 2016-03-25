#include <stdio.h>

/*

Problema: 

Eh dado um mapa inicialmente como esse abaixo.

###############################################################
#..........#.......#...........................#T............T#
#...T......#..###TT#...........................#..............#
#..........#..#.####...........................#..............#
#.....T....#..#................................#..............#
#..........#.##......TT........................#..............#
#......T...#.#................................T#T............T#
#.##########.#...........TT..............######################
#.#..........#...........................#TTTTT#..............#
#.#...####################################TTTTT#.......T......#
#.....#..................................#TTTTT#..............#
#######..................................#TTTTT#..............#
#T....#..................................####################.#
#.....#..................................#....................#
#.....#..................................#....................#
#.....#..............................#####....................#
#.##########.........................#....#...................#
#..........###########################.....#..................#
##########.#T........................#......#.................#
#..........#.........................#.......#................#
#..........#.........................#........#...............#
#..........#.........................#.........#..............#
#..........#.........................#..........#.............#
#..........##########................#T..........#............#
#...................#####............##########################
#......................T#.................................TTTT#
###############################################################

Descobrir para cada posicao P(X,Y) na entrada, informar
          a posicao de cada tesouro ('T') que um personagem  
          alcanca caminhando livremente a partir de P. 
          (coords comecam de 0,0 e segue a logica do array em C)
          O personagem soh pode caminhar norte, sul, leste, oeste e nao
          pode passar entre as paredes '#'.

tamanho maximo do tabuleiro = 100 x 100

*/

typedef struct coords
{
	int i, j;
} coords;

int m, n; 
char mapa[100][100+1];
coords tesouros[100 * 100];
coords all_pos[4 * 100 * 100];
coords marcadas[100 * 100];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int ler_mapa()
{
	if(scanf("%d%d",&n,&m) != 2) return 0;
	int i;
	for(i=0;i<n;i++)      
		scanf("%s", mapa[i]); 
	return 1;         
}

// QUESTAO: TEM COMO FAZER MELHOR EM MEMORIA E TEMPO?
//          EM CASO POSITIVO, A COMPLEXIDADE TB MELHORA?

void resolve(int x, int y)
{
	printf("BEGIN\n");
	coords init;
	init.i = x; init.j = y;
	int nt = 0, np = 0, nm = 0;
	all_pos[np++] = init;
	int k, w;
	for(k=0; k<np; k++) {
		int i = all_pos[k].i;
		int j = all_pos[k].j; 
		if(i < 0 || i >= n) continue;
		if(j < 0 || j >= m) continue;
		if(mapa[i][j] == 'X' || mapa[i][j] == '#') continue;
		if(mapa[i][j] == 'T') tesouros[nt++] = all_pos[k];
		mapa[i][j] = 'X'; marcadas[nm++] = all_pos[k];
		for(w=0;w<4;w++) {
			coords novo;
			novo.i = i + dir[w][0]; novo.j = j + dir[w][1];
			all_pos[np++] = novo;
		}
	}
	for(k=0;k<nm;k++) mapa[marcadas[k].i][marcadas[k].j] = '.';
	if(nt == 0) {
		if(mapa[x][y] == '.') printf("Nenhum tesouro foi encontrado a partir de (%d,%d).\n",x,y);
		else printf("Estou em cima do muro ;-/\n");
		
	} else {
		printf("A partir de (%d,%d) temos:\n",x,y);
		for(k=0;k<nt;k++) {
			mapa[tesouros[k].i][tesouros[k].j] = 'T';
			printf("- tesouro em (%d,%d)\n",tesouros[k].i,tesouros[k].j);
		}
	}
	printf("END\n\n");
}

void processa()
{
	int ncasos;
	scanf("%d",&ncasos);
	while(ncasos--) {
		int x, y;
		scanf("%d%d",&x,&y);
		resolve(x,y);
	}
}

int main() 
{
	
 	freopen ("exercicio1.in","r",stdin);
 	freopen ("exercicio1.out","w",stdout);

	while(ler_mapa())
	{
		processa();
	}
	
	return 0;
}