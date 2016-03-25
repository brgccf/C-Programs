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

int tab[4][4], aux[4][4], pontuacao=0, pontuacao_aux=0, tamanho_rep=16;

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
	int fundir=1, gravidade=1;
	fundir=fundir_casas(comando);
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
			}
		}
	}
	if(pode) return 1;
	//verificando da direita pra esquerda
	for(i = 3; i > -1; i--)
	{
		for(j = 3; j > -1; j--)
		{
			if(i != 0 && tab[i][j] == tab[i-1][j]) pode = 1;
		}
	}
	if(pode) return 1;

	return 0;
}

//comandos para IA

int can_up(int coluna)
{
	int i, j, k;
	i=coluna;
	for (j=0;j<4;j++) {
		if (tab[j][i]!=0) {
			for (k=j;k<4;k++) {
				if (k!=j&&tab[k][i]!=tab[j][i]&&tab[k][i]!=0) break;
				else if (k!=j&&tab[k][i]==tab[j][i]) {
					return 1;
				}
			}
		} else {
			for (k=j;k<4;k++) {
				if (tab[k][i]!=0) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int can_down(int coluna)
{
	int i, j, k;
	i=coluna;
	for (j=3;j>=0;j--) {
		if (tab[j][i]!=0) {
			for (k=j;k>=0;k--) {
				if (k!=j&&tab[k][i]!=tab[j][i]&&tab[k][i]!=0) break;
				else if (k!=j&&tab[k][i]==tab[j][i]) {
					return 1;
				}
			}
		} else {
			for (k=j;k>=0;k--) {
				if (tab[k][i]!=0) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int can_left(int linha)
{
	int i, j, k;
	i=linha;
	for (j=0;j<4;j++) {
		if (tab[i][j]!=0) {
			for (k=j;k<4;k++) {
				if (k!=j&&tab[i][k]!=tab[i][j]&&tab[i][k]!=0) break;
				else if (k!=j&&tab[i][k]==tab[i][j]) {
					return 1;
				}
			}
		} else {
			for (k=j;k<4;k++) {
				if (tab[i][k]!=0) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int can_right(int linha)
{
	int i, j, k;
	i=linha;
	for (j=3;j>=0;j--) {
		if (tab[i][j]!=0) {
			for (k=j;k>=0;k--) {
				if (k!=j&&tab[i][k]!=tab[i][j]&&tab[i][k]!=0) break;
				else if (k!=j&&tab[i][k]==tab[i][j]) {
					return 1;
				}
			}
		} else {
			for (k=j;k>=0;k--) {
				if (tab[i][k]!=0) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int get_pivo()
{
	int i;
	for (i=0;i<4;i++) {
		if (can_right(i)||can_left(i)) return i+1;
	}
	return 0;
}

void record_state()
{
	int i, j;
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++) {
			aux[i][j]=tab[i][j];
		}
	}
	pontuacao_aux=pontuacao;
}

void return_state()
{
	int i, j;
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++) {
			tab[i][j]=aux[i][j];
		}
	}
	pontuacao=pontuacao_aux;
}

int simulate(int in1, int in2, int in3, int in4)
{
	/*
	o metodo simula uma jogada de acordo com os argumentos, ele tenta prever ate
	4 jogadas no futuro, porem sem a simulacao randomica
	obs.:
	1-caso um movimento nao foi possivel de ser aplicado ele vai para o final da simulacao
	2-ele grava o estado em que se encontrava o tabuleiro, simula em cima dele e depois
	volta ao estado anterior
	*/
	record_state();
	int out, check;
	check=aplicar(in1);
	if (!check) goto f;
	check=aplicar(in2);
	if (!check) goto f;
	check=aplicar(in3);
	if (!check) goto f;
	check=aplicar(in4);
	if (!check) goto f;
	f:
	out=pontuacao - pontuacao_aux;
	return_state();
	return out;
}

int gen_move()
{
	/*
	o for simula todas as combinacoes possiveis e pega o valor da maior simulacao
	e a ref que sinaliza que comando tomar
	obs.:
	os returns do final e para garantir que voce pode gerar o movimento
	*/
	int i, j, k, l, m, n, o, p, maior=0, a[256], ref, up, down, left, right;
	for (i=0, j=-1, k=-1, l=-1;i<256;i++) {
		if (i%4==0) j++;
		if (i%4==0&&j%4==0) k++;
		if (i%4==0&&j%4==0&&k%4==0) l++;
		a[i]=simulate(i%4,j%4,k%4,l%4);
		if (maior<a[i]) {
			maior=a[i];
			ref=i%4;
		}
	}
	aplicar(ref);
	for (i=0;i<4;i++) if (can_up(i)||can_right(i)||can_down(i)||can_left(i)) return 1;
	return 0;
}

int main()
{
	char entrada='2';
	int comando=0, check=1, check_aux=0;
	srand(time(NULL));
	printf("=================================\n========2048-PUZZLE GAME=========\n=================================\n");
	printf("1 - P1\n2 - IA\n");
	scanf(" %c", &entrada);
	resetar_tabuleiro();
	gerar_casa();
	gerar_casa();
	imprimir_tabuleiro();
	if (entrada=='1') goto p;
	else if (entrada=='2') goto ia;
	p:
	//jogador pessoa
	for (scanf(" %c", &entrada);entrada!='q'&&(check||tamanho_rep>0);scanf(" %c", &entrada)) {
		if (to_wasd(entrada)) {
			if (check_aux) {
				check_aux=0;
				gerar_casa();
			}
			check=gerar_casa();
		}

		organizar_rep();
		imprimir_tabuleiro();
    if(!verifica_casas())
    {
    	if(!pode_fundir()) goto end;
		}
	}
	if (entrada=='q') goto end;
	//IA
	ia:
	//FIM DA IA
	to_wasd('w');
	gerar_casa();
	imprimir_tabuleiro();
	int i;
	for (i=0;gen_move();i++) {
		organizar_rep();
		gerar_casa();
		imprimir_tabuleiro();
	}
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
	printf("Fim de jogo.  Sua pontuacao foi: %d\n", pontuacao);
	return 0;
}
