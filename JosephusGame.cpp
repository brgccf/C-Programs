#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int key;
    struct no *next;

}no;
no *head = NULL, *aux = NULL;

//insere elementos na lista (1º passo do algoritmo)
void inserir(int key)
{
    no *novo = (no*) malloc (sizeof(no));
    novo->key = key;
    //novo->next = NULL; não será mais necessario
    novo->next = head;
    if(!head) head = aux = novo;
    else{
        aux->next = novo;
        aux = aux->next;
    }
}

//metodo remover para cada elemento após percorrer k elementos
void remove_jos()
{
    no *temp = head;
    aux->next = head->next;
    printf("==REMOVED: %d==\n", temp->key);
    free(temp);
    head = aux->next;
}

//implementando jogo do Josethus
void josephus(int n, int k)
{
    int i;
    if(head == head->next)
    {
        printf("The survivor is: %d\n", head->key);
        return;
    }
    for(i = 1; i < k; i++)
    {
        aux = aux->next;
        head = head->next;
    }
    remove_jos();
    n--;
    josephus(n, k);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int i;
    for(i = 1; i <= n; i++) inserir(i);

    //print_elements();
    printf("===JOSEPHUS GAME===\n");
    josephus(n, k);

    return 0;
}
