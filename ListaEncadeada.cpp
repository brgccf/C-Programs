#include <stdio.h>

typedef struct no
{
	int key;
	struct no* next;
}no;
no *head, *aux;
//head aponta pro inicio da lista e aux aponta pro final
void insert(int key)
{
	no *novo = (no*) malloc(sizeof(no));
	novo->key = key;
	novo->next = NULL;
	if(!head) head = aux = novo;
	else
	{
		aux->next = novo;
		aux = aux->next;
	}
}

void remove_top()
{
	if(!head) return;
	no *temp = head;
	head = head->next;
	free(temp);
}

int is_empty()
{
	return !head;
}

//inserindo elementos no meio
void insert_middle(int key, int k_search)
{
	no *node = search(k_search);
	if (!node) return;
	no *novo = (no*) malloc (sizeof(no));
	novo->key = key;
	novo->next = node->next;
	node->next = novo;
	if(!aux->next) aux = novo;
}

//procurando um elemento
no *search(int key)
{
	no *temp;
	for(temp = head; temp; temp = temp->next)
	{
		//quando temp por nulo, sai do for. a cada iteração temp apontará pro prox elemento
		if(temp->key == key)
		{
			return temp;
		}
	}
	return NULL;
}
