#include <bits/stdc++.h>
#include <time.h>

int cases;

using namespace std;
typedef struct no
{
	int key;
	int prio;
	no(int b,int a):key(a),prio(b){}
	
	struct no* next;
}no;
no *head, *aux;
/*
	Na fila, devemos aplicar a logica FIFO (First-in, First-out)
	--> o primeiro elemento que entrar, é o primeiro a sair.
	--> head sempre aponta pro primeiro elemento
*/

void insert_ele(int k, int p)
{
	no *novo = new no(k, p);
	// no *novo = (no*) malloc (sizeof(no));
	novo->key = k;
	novo->prio = p;
	novo->next = NULL;
	if(!head) head = aux = novo;
	else{
		aux->next = novo;
		aux = novo;
	}
}

void remove_top()
{
	if(!head) return;
	if (head->next == NULL)
	{
		no *temp = head;
		free(temp);
	}
	else{
		no *temp = head;
		head = head->next;
		free(temp);
	}
}

void print_queue(int n){
	int i;
	no *temp = head;
	printf("==FILA ATUAL: ==\n");
	printf("KEY:\n");
	for (i = 0; i < n; ++i)
	{
		printf("%d \n", temp->key);
		if (temp->next == NULL) break;
		temp = temp->next;
	}
	temp = head;
	printf("PRIO:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d \n", temp->prio);
		if (temp->next == NULL) break;
		temp = temp->next;
	}
}

int main(int argc, char const *argv[])
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d", &cases);
	int n, m, finished = 1;
	int minutes;
	vector<int> queu;
	while(cases)
	{
		
		if(finished){
			queu.clear();
			scanf("%d%d", &n, &m);
			for (int j = 0; j < n; j++)
			{
				queu.push_back(0);
			}
			minutes = 0;
		}
		
		int i;
		
		//inserindo valores na fila
		if (finished)
		{
			for (i = 0; i < n; ++i)
			{
				scanf("%d", &queu[i]);
				printf("===TENTANDO INSERIR===\n");
				insert_ele(i, queu[i]);
				printf("==CONSEGUIU INSERIR===\n");
			}
			finished = 0;
		}
		
		
		//verificando no array qual a maior prioridade usando array queue
		int temp = 0;
		for (i = 0; i < n; ++i)
		{
			if (queu[i] > temp)
			{
				temp = i;
				printf("==TEMP = %d==\n", temp);
			}
		}
		print_queue(n);
		//na variavel temp, temos exatamente quantas vezes vamos
		//precisar jogar elementos para o final da fila
		//ate chegar no elemento de maior prioridade
		if (n > 1)
		{
			printf("===N > 1===\n");
			for (i = 0; i < temp; ++i)
			{
				printf("movendo fila\n");
				aux->next = head;
				no *check = head->next;
				head->next = NULL;
				head = check;
				aux = aux->next;
				--m;
				if (m == 0)m+=temp;
			}
		}
		print_queue(n);
		printf("=== M = %d\n", m);
		//depois de ordenada a fila, eliminamos o elemento
		//verificando se eh o que queremos

		printf("HEAD PRIO = %d\n", head->prio);
		printf("HEAD KEY = %d\n", head->key);
	
		if (head->key == m)
		{
			printf("RESULT = %d min\n", minutes);
			--cases;
			finished = 1;
		}
		++minutes;
		remove_top();
		--n;
	}
	return 0;
}