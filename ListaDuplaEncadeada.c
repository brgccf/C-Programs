#include <stdio.h>
//imprima elementos de n a 1
typedef struct no
{
    int key;
    struct no *next, *prev;

}no;
no *head = NULL; *aux = NULL;


void remove()
{
    if(!head) return;
    no *temp = head;
    head = head->next;
    if(head){

    head->prev = NULL;
    free(temp);
    }

}

void inserir(int key)
{
    no *novo = (no*) malloc (sizeof(no));
    novo->key = key;
    novo->next = NULL;
    novo->prev = NULL;
    if(!head) head = aux = novo;
    else{
        aux-> next = novo;
        aux = aux->next;
        novo->prev = aux;
    }

}
