#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
resetar_tabuleiro OK
gerar_casa OK
organizar_rep OK
imprimir_tabuleiro OK
fundir_casas OK
aplicar_gravidade OK
aplicar OK
*/

unsigned int left = 0, right = 0, up = 0, down = 0, finish = 0;
int tab[4][4], pontuacao = 0, tamanho_rep=16;

struct Casa
{
	int x;
	int y;
};

Casa rep[16]= {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 1},
{1, 2}, {1, 3}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {3, 0},
{3, 1}, {3, 2}, {3, 3}};

void organizar_rep() //reorganiza o repositorio com base nas casas ocupadas
{
	int i, j, a, y, x;
	Casa aux[16];
	for (a=0, i=0, j=15;a<16; a++) {
		y = rep[a].y;
		x = rep[a].x;
		if (tab[y][x]==0) {
			aux[i]=rep[a];
			i++;
		} else {
			aux[j]=rep[a];
			j--;
		}
	}
	tamanho_rep=(j+1);
	for (i=0;i<16;i++) {
		rep[i] = aux[i];
	}
}

void resetar_tabuleiro() //inicializa o tabuleiro com 0 em todas as casas
{
	int i, j;
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++) {
			tab[i][j]=0;
		}
	}
}

int gerar_casa() //gera um 2 aleatorio numa casa livre com base no repositorio
{
	if (tamanho_rep==0) return 0;
	int x, y, get_rep, count=0;
	Casa random;
	l:
	if (tamanho_rep>1) get_rep = rand()%(tamanho_rep);
	else get_rep = 0;
	random = rep[get_rep];
	x = random.x;
	y = random.y;
	if (tab[y][x]!=0) {
		organizar_rep();
		goto l;//retorna ao ponto l caso a casa gerada se encontre ocupada e ele reorganiza o repositorio so por via das duvidas
	}
	tamanho_rep--;
	rep[get_rep]=rep[tamanho_rep];//permutaçao de casas
	rep[tamanho_rep]=random;
	tab[y][x]=2;
	if (tamanho_rep>=0) return 1;
	// retorna 1 se conseguiu gerar
	// retorna 0 se nao conseguiu gerar
	/*O programa troca a casa escolhida
	com a ultima casa do array e diminui
	o range de busca no mesmo */
}

void imprimir_tabuleiro()//imprime o tabuleiro
{
	int i, j;
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++) {
			printf("|%4d", tab[i][j]);
		}
		printf("|\n");
	}
	printf("Score: %d\n", pontuacao);
}

int fundir_casas(int comando)//retorna 1 caso foi possivel fundir casas e caso nao retorna 0
{
	int i, j, k, check=0;
	switch (comando) {
		//down
		case 0:
		for (i=0;i<4;i++) {
			for (j=3;j>=0;j--) {
				if (tab[j][i]!=0) {
					for (k=j;k>=0;k--) {
						if (k!=j&&tab[k][i]!=tab[j][i]&&tab[k][i]!=0) break;
						else if (k!=j&&tab[k][i]==tab[j][i]) {
							tab[j][i] = tab[j][i]*2;
							pontuacao+=tab[j][i];
							tab[k][i] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
		//right
		case 3:
		for (i=0;i<4;i++) {
			for (j=3;j>=0;j--) {
				if (tab[i][j]!=0) {
					for (k=j;k>=0;k--) {
						if (k!=j&&tab[i][k]!=tab[i][j]&&tab[i][k]!=0) break;
						else if (k!=j&&tab[i][k]==tab[i][j]) {
							tab[i][j] = tab[i][j]*2;
							pontuacao+=tab[i][j];
							tab[i][k] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
		//left
		case 2:
		for (i=0;i<4;i++) {
			for (j=0;j<4;j++) {
				if (tab[i][j]!=0) {
					for (k=j;k<4;k++) {
						if (k!=j&&tab[i][k]!=tab[i][j]&&tab[i][k]!=0) break;
						else if (k!=j&&tab[i][k]==tab[i][j]) {
							tab[i][j] = tab[i][j]*2;
							pontuacao+=tab[i][j];
							tab[i][k] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
		//up
		case 1:
		for (i=0;i<4;i++) {
			for (j=0;j<4;j++) {
				if (tab[j][i]!=0) {
					for (k=j;k<4;k++) {
						if (k!=j&&tab[k][i]!=tab[j][i]&&tab[k][i]!=0) break;
						else if (k!=j&&tab[k][i]==tab[j][i]) {
							tab[j][i] = tab[j][i]*2;
							pontuacao+=tab[j][i];
							tab[k][i] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
	}
	return check;
}

int aplicar_gravidade(int comando) //aplica a gravidade e retorna 1 caso algo mudou e 0 caso nada tenha mudado
{
	int i, j, k, check=0;
	switch (comando) {
		//down
		case 0:
		for (i=0;i<4;i++) {
			for (j=3;j>=0;j--) {
				if (tab[j][i]==0) {
					for (k=j;k>=0;k--) {
						if (tab[k][i]!=0) {
							tab[j][i] = tab[k][i];
							tab[k][i] = 0;
							check=1;
							break;
						}
					}
				}
		}
			}
		break;
		//right
		case 3:
		for (i=0;i<4;i++) {
			for (j=3;j>=0;j--) {
				if (tab[i][j]==0) {
					for (k=j;k>=0;k--) {
						if (tab[i][k]!=0) {
							tab[i][j] = tab[i][k];
							tab[i][k] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
		//left
		case 2:
		for (i=0;i<4;i++) {
			for (j=0;j<4;j++) {
				if (tab[i][j]==0) {
					for (k=j;k<4;k++) {
						if (tab[i][k]!=0) {
							tab[i][j] = tab[i][k];
							tab[i][k] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
		//up
		case 1:
		for (i=0;i<4;i++) {
			for (j=0;j<4;j++) {
				if (tab[j][i]==0) {
					for (k=j;k<4;k++) {
						if (tab[k][i]!=0) {
							tab[j][i] = tab[k][i];
							tab[k][i] = 0;
							check=1;
							break;
						}
					}
				}
			}
		}
		break;
	}
	return check;
}

int aplicar(int comando) {//retorna 1 caso houve mudança e 0 caso nao
	// tarefa 4:
	// implemente uma funcao para fundir
	// casas de mesmo valor conforme o
	// comando solicitado
	// e atualizar pontuacao
	int fundir=1, gravidade=1;
	fundir=fundir_casas(comando);
	// tarefa 5:
	// vamos aplicar a gravidade no sentido
	// indicado por comando no tabuleiro
	gravidade=aplicar_gravidade(comando);
	if (fundir||gravidade) return 1;
	else return 0;
}
int to_wasd(char in) //transforma o input padrao de 0, 1, 2, 3 para wasd para ser mais intuitivo
{
	switch (in) {
		case 'w':
		return aplicar(1);
		break;
		case 'a':
		return aplicar(2);
		break;
		case 's':
		return aplicar(0);
		break;
		case 'd':
		return aplicar(3);
		break;
	}
}

int verifica_casas() //retorna 1 se encontrar casa vazia. 0 caso contrario
{
    unsigned int retorno = 0;
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(tab[i][j] == 0) retorno = 1;
        }
        if(retorno) break;
    }

    return retorno;

}

int pode_fundir() //retorna 1 se puder, 0 se nao.
{
    int i, j;
    unsigned int pode = 0;
    //verifica se pode fundir

    //verificando de cima pra baixo
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(j != 3 && tab[i][j] == tab[i][j+1])
			{
				pode = 1;
				down = 1;
			}
		}
	}

	if(pode) return 1;
	//verificando de baixo para cima
	for(i = 3; i > -1; i--)
	{
		for(j = 3; j > -1; j--)
		{
			if(j != 0 && tab[i][j] == tab[i][j-1])
			{
				 pode = 1;
				 up = 1;	
			}	
		}	
	}
	if(pode) return 1;
	//verificando da esquerda pra direita
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(i != 3 && tab[i][j] == tab[i+1][j])
			{
				pode = 1;
				right = 1;
			}
		}
	}	
	if(pode) return 1;
	//verificando da direita pra esquerda
	for(i = 3; i > -1; i--)
	{
		for(j = 3; j > -1; j--)
		{
			if(i != 0 && tab[i][j] == tab[i-1][j])
			{
				pode = 1;
				left = 1;	
			} 
		}
	}
	if(pode) return 1;
	
	return 0;
}

//fun�ao para IA:
int pode_fundir_IA() //retorna 1 se puder, 0 se nao.
{
    int i, j;
    unsigned int pode = 0;
    //verifica se pode fundir

    //verificando de cima pra baixo
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(j != 3 && tab[i][j] == tab[i][j+1])
			{
				pode = 1;
				down = 1;
			}
		}
	}

	//verificando de baixo para cima
	for(i = 3; i > -1; i--)
	{
		for(j = 3; j > -1; j--)
		{
			if(j != 0 && tab[i][j] == tab[i][j-1])
			{
				 pode = 1;
				 up = 1;	
			}	
		}	
	}
	//verificando da esquerda pra direita
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(i != 3 && tab[i][j] == tab[i+1][j])
			{
				pode = 1;
				right = 1;
			}
		}
	}	
	//verificando da direita pra esquerda
	for(i = 3; i > -1; i--)
	{
		for(j = 3; j > -1; j--)
		{
			if(i != 0 && tab[i][j] == tab[i-1][j])
			{
				pode = 1;
				left = 1;	
			} 
		}
	}
	if(pode) return 1;
	
	return 0;
}

//recebe o estado do jogo como entrada e retorna um comando
char artificial_inteligence(int tab[4][4])
{
	if(pode_fundir_IA())
	{
		if(up)
		{
			printf("===CIMA===\n");
			up = 0;
			return 'w';
		}
		if(right)
		{
			printf("===DIREITA===\n");
			right = 0;
			return 'd';	
		}
		if(left)
		{
			printf("===ESQUERDA===\n");
			left = 0;
			return 'a';
		}
		if(down) 
		{
			printf("===BAIXO===\n");
			down = 0;
			return 's';
		}
	}
	else finish = 1;
	
}


int main()
{
	char entrada='e';
	int comando=0, check=1, check_aux=0;
	srand(time(NULL));
	printf("=================================\n========2048-PUZZLE GAME=========\n=================================\n");
	printf("1 - P1\n2 - IA\n");
	scanf(" %c", &entrada);
	if (entrada=='1') goto p;
	else if (entrada=='2') goto ia;
	p:
	resetar_tabuleiro();
	gerar_casa();
	gerar_casa();
	imprimir_tabuleiro();
	//jogador pessoa
	for (scanf(" %c", &entrada);entrada!='q'&&(check||tamanho_rep>0);scanf(" %c", &entrada)) {
		if (to_wasd(entrada)) {
			if (check_aux) { check_aux=0; gerar_casa();}
			check=gerar_casa();
		}

		organizar_rep();
		imprimir_tabuleiro();
		//verificando se o jogo acabou
        if(!verifica_casas())
        {
        	//se nao pode fundir nenhuma, mesmo estando tudo preenchido, finaliza.
          	if(!pode_fundir()) goto end;
		}
	}
	if (entrada=='q') goto end;
	//IA
	ia:
		resetar_tabuleiro();
		gerar_casa();
		gerar_casa();
		imprimir_tabuleiro();
		while(1)
		{
			char move = artificial_inteligence(tab);
			to_wasd(move);
			imprimir_tabuleiro();
			if(finish) goto end;
			gerar_casa();
		}
	//FIM DA IA

	// restante da tarefa:
	// aceitar comando
	// down - 0, up - 1,
	// left - 2, right - 3
	// aplica-lo no tabuleiro

 	// e faca a logica do jogo
	// (loop principal)
	// o jogo comeca posicionando
	// aleatoriamente dois valores 2
	// o jogo termina quando nao eh
	// mais possivel posicionar valores
	// cada vez que duas casas se fundem
	// voce ganha a soma dos valores
	// nas casas originais em pontuacao
	// voce pode acessar o jogo em
	// http://gabrielecirulli.github.io/2048/

	// desafio:  gere uma sequencia de movimentos (IA)
	//           simulando-a com o seu programa
	//           envie para tpshc2@cin.ufpe.br o seu programa.
	//           se ela atingir 1024 em uma execucao,
	//           do monitor, voce ganha bonus (se tiver
	//           a maior pontuacao dentre os que enviaram).
	// ATENCAO:  se a regra do jogo nao estiver implementada
	//           corretamente, perde 1 ponto na prova.
	end:
	    printf("Fim de jogo.  Sua pontuacao foi: %d", pontuacao);

	return 0;
}
