#include <stdio.h>

typedef struct no
{
	int key;
	struct no *next;
	
}no;
no *head, *aux;

void push(int key)
{
	no *novo = (*no) malloc (sizeof(no));
	novo->key = key;
	novo->next = head;
	head = novo;
}

void pop()
{
	if(!head) return;
	no *temp = head;
	head = head->next;
	free(temp);
}
