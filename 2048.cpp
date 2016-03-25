#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tab[4][4], pontuacao;
int casas_vazias[17];
unsigned char aux = 'x';

void resetar_tabuleiro()
{
	int i, j;
	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			tab [i][j] = 0;
		}
	}
	pontuacao = 0;
}

int gerar_casa()
{
	//EASY_MODE
	/*int r = rand()%4;
	int r2 = rand()%4;
	if(tab[r][r2] == 0)
	{
		tab[r][r2] = 2;
		return 1;
	}
	else
	{
		//verificando se ha casa vazia quando nao achar
		int achou = 0;
		int i, j;
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				if(tab[i][j] == 0)
				{
					achou = 1;
					tab[i][j] = 2;	
				}
			}
		}
		if(achou)
		{
			return 1;
			
		}
		else return 0;
	}
	// retorna 1 se conseguiu gerar
	// retorna 0 se nao conseguiu gerar

	*/
	//HARD_MODE
	int i;
	for(i = 0; i < 17; i++)
	{
		casas_vazias[i] = 0;
	}
	//variavel auxiliar posiciona-se no final do array
	casas_vazias[17] = aux;
	
}

void imprimir_tabuleiro()
{
	int i, j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf ("|%d", tab[i][j]);
		}
		printf("|\n");
	}
}

void fundir_casas(int comando)
{
	int i, j;
	//2 = down; 4 = left; 6 = right ; 8 = up.
	switch(comando)
	{
		case (2):
			
			//verificação de baixo para cima
			// eixo x diminui enquanto o y se mantem
			for(j = 3; j > -1; j--)
			{
				for(i = 3; i > -1; i--)
				{
					if(j != 0 && tab[i][j] == tab[i][j-1])
					{
						//efetua a soma e altera o valor de cima para 1, para evitar dupla soma
						tab[i][j] += tab[i][j-1];
						tab [i][j-1] = 1;
					}
				}
			}
			//altera os valores 1 para 0
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(tab[i][j] == 1) tab[i][j] = 0;
				}
			}
		break;
		case(4):
			//verificação da esquerda para direita
			//eixo y aumenta enquanto eixo x se mantem
			
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(i != 3 && tab[i][j] == tab[i+1][j])
					{
						//efetua o mesmo processo do caso 2
						tab[i][j] += tab[i+1][j];
						tab [i+1][j] = 1;
					}
				}
			}
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(tab[i][j] == 1) tab[i][j] = 0;
				}
			}
		break;
		case(6):
			//verificação da direita para esquerda
			//eixo y diminui enquanto eixo x se mantem
			
			for(i = 3; i > -1; i--)
			{
				for(j = 3; j >-1; j--)
				{
					
					if(i != 0 && tab[i][j] == tab[i-1][j])
					{
						tab[i][j] += tab[i-1][j];
						tab[i-1][j] = 1;
					}
				}
			}
			//alterando os valores 1 para 0
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(tab[i][j] == 1) tab[i][j] = 0;
				}
			}
		case(8):
			//verificacao de cima para baixo
			//eixo x aumenta enquanto eixo y se mantem
			
			for(j = 0; j < 4; j++)
			{
				for(i = 0; i < 4; i++)
				{
					if(j != 3 && tab[i][j] == tab[i][j+1])
					{
						tab[i][j] += tab[i][j+1];
						tab[i][j+1] = 1;
					}
				}
			}
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(tab[i][j] == 1) tab[i][j] = 0;
				}
			}	
	}
	
	
}

void aplicar_gravidade(int comando)
{
	
}

void aplicar(int comando) {
	// vamos dividir essa funcao
	// em duas logicas separadas
	
	// tarefa 4:
	// implemente uma funcao para fundir
	// casas de mesmo valor conforme o 
	// comando solicitado
	// e atualizar pontuacao
	fundir_casas(comando);
	
	// tarefa 5:
	// vamos aplicar a gravidade no sentido
	// indicado por comando no tabuleiro
	aplicar_gravidade(comando);
}

int main()
{
	srand(time(NULL)); // possibilitar mudar a 
	                   // semente do numero aleatorio
	                   // para gerar numero aleatorio 
	                   // de 0 a 3, use int r = rand()%4
	resetar_tabuleiro(); // tarefa 1: inicializar tab com 0's
	                     //           e pontuacao com 0
	gerar_casa();
	gerar_casa();        // tarefa 2: implemente uma funcao
	                     //           que gera um valor 2
	                     //           em alguma casa vazia
	                     //           aleatoria
	imprimir_tabuleiro(); // tarefa 3: imprimir tabuleiro 
	                     //           na tela
	//aplicar(int comando); // restante da tarefa:
	                      // aceitar comando
	                      // down - 2, up - 8,
	                      // left - 4, right - 6
	                      // aplica-lo no tabuleiro
	           
	// tarefa final:  // use as funcoes implementadas
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
	               
	return 0;
}

