/*
O seu programa deve receber um número N de arquivos, um número T <= N de threads, um número
F de tipos de flechas e um vetor P de tamanho F, onde P[i] = custo do conserto de uma
unidade do i-ésimo tipo de flecha. Para o propósito do programa, o vetor P pode ser
inicializado estaticamente. Ademais, seu programa deverá ter o vetor custo_ruim de
dimensão F, o qual representa a custo de total de consertar as unidades i lidas em cada
arquivo, ex. custo_ruim[i] = 5 * P[i]. Uma variável contador_bom deve ser utilizada para
contar a quantidade flechas (independente do tipo) em bom estado.

Cada arquivo terá 2 números por linha, <f, q> tal que f é o tipo da flecha (entre 0 e F-1) e q é
a quantidade desse tipo de flecha. Caso q < 0, você precisará calcular o preço para consertar
as |q| flechas, caso contrário, apenas incremente a quantidade de flechas em bom estado.
Cada thread deverá pegar um arquivo. Quando uma thread concluir a leitura de um arquivo, e
houver um arquivo ainda não lido, a thread deverá ler algum arquivo pendente. No final,
imprima o total de flechas boas e para cada tipo de flecha, imprima o preço do conserto delas.

Assumindo o conhecimento prévio da quantidade de threads e arquivos, pode-se definir no
início do programa quais arquivos a serem tratados por cada thread. Uma outra alternativa é
ler os arquivos sob demanda, a partir do momento que uma thread termina a leitura de um
arquivo, pega qualquer outro não lido dinamicamente.

ATENÇÂO: deve-se garantir a exclusão mútua ao alterar o vetor que guardará o custo
do conserto de cada flecha. Porém, você deverá assumir uma implementação refinada.
Uma implementação refinada garante a exclusão mútua separada para cada posição do
vetor. Mais especificamente, enquanto um preço está sendo contabilizado para um tipo
de flecha x e modificando o vetor na respectiva posição, uma outra thread podemodificar o vetor em 
uma posição y que representa outra flecha.
Ou seja, se o vetor de
flechas possui tamanho 10, haverá um outro vetor de 10 mutex, um para cada posição
do vetor de flechas. Ao ler um arquivo e detectar um conserto para a flecha y, a thread
trava o mutex relativo à posição y, calcula o preço, e destrava o mutex na posição y.
Obviamente, se mais de uma thread quiser modificar a mesma posição do vetor de
flechas simultaneamente, somente 1 terá acesso, e as outras estarão bloqueadas. O
mutex garantirá a exclusão mútua na posição.
A variável contador_bom é uma região crítica, e, assim, deve-se garantir também uma
exclusão mútua específica para alterar esta variável.

Exemplo:
T = 1 // no de threads
N = 1 // no de arquivos
F = 3 // no de flechas
P[3] = {2, 3, 7} // preço de cada flecha
Arquivo de entrada 1.in:
2 10
1 -2
0 3
2 3
Saída:
16 flechas em bom estado!
Custo de consertar as flechas de tipo 0: R$ 0,00
Custo de consertar as flechas de tipo 1: R$ 6,00
Custo de consertar as flechas de tipo 2: R$ 0,00
*/
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

vector<int> P;
vector<int> custo_ruim;
int contador_bom = 0;

pthread_mutex_t mutex_lock_bom;
vector<pthread_mutex_t> mutex_lock_vec;

void *calcula_custo_bom(*void param)
{

}

void *calcula_custo_ruim(*void param)
{
	
}

int main()
{
	int N, T, F; //N = num. arquivos, T = num. threads, F = tipos de flechas
	scanf("%d%d%d", &T, &N, &F); //leitura de parametros
	P.resize(F); //definindo P com o total de tipos de flechas.
	custo_ruim.resize(F); //definindo custo_ruim com F tipos de flechas
	mutex_lock_vec.resize(F); //definindo mutex para cada posicao do vetor
	pthread_t calc_ruim, calc_bom; //threads para cada calculo


	while(N--) //enquanto houver arquivos para serem lidos
	{
		int f, q; //f = tipo de flecha (até F-1), q = qtde do tipo de flecha
		scanf("%d%d", &f, &q);
	}
	

	return 0;
}
