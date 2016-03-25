#include <stdio.h>

unsigned int array[] = {3, 5, 1, 7, 2};

typedef struct list
{
	int key;
	struct *list next;
}list;
list *head, *aux;
//head aponta pro inicio e aux aponta pro final

list* search(int key)
{
	list* temp;
	for(temp = head; temp; temp = temp->next)
	{
		if(temp->key == key) return temp; 
	}
	return NULL;
}

void insert(int key, int k_search)
{
	list *node = search(k_search);
	if(!node) return;
	novo->next = NULL;
	if(!head) head = aux = novo;
	else
	{
		aux->next = novo;
		aux = aux->next;
	}
}

int main()
{
	int i;
	for(i = 0; i < 5; i++)
	{
		insert(array[i], array[i]);
	}
	
	return 0;
}


