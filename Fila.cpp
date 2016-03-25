#include <bits/stdc++.h>
#include <time.h>
typedef struct no
{
	int key;
	struct no* next;
}no;
no *head, *aux;
/*
	Na fila, devemos aplicar a logica FIFO (First-in, First-out)
	--> o primeiro elemento que entrar, é o primeiro a sair.
	--> head sempre aponta pro primeiro elemento
*/

void inserir(int k)
{
	no *novo = (no*) malloc (sizeof(no));
	novo->key = k;
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
	no *temp = head;
	head = head->next;
	free(temp);
}

int top_element()
{
	return head->key;
}

int main(int argc, char const *argv[])
{
	printf("Gerando valores aleatorios\n");
	int i;
	for (i = 0; i < 5; ++i)
	{
		inserir(i);
	}
	printf("Elementos gerados:\n");
	no *temp = head;
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", temp->key);
		temp = temp->next;
	}
	printf("Elemento do topo atual:\n");
	printf("%d\n", top_element());
	printf("Removendo elemento do topo + impressao do novo elemento:\n");
	remove_top();
	printf("%d\n", top_element());
	printf("Fim de programa\n");
	return 0;
}