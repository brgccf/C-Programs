#include <stdio.h>
#include <stdlib.h>
//imprima elementos de 1 a n
typedef struct no
{
    int key;
    struct no *next;

}no;
no *head = NULL, *aux = NULL;

no* search(int key)
{
    no *temp;
    for (temp = head; temp->next != head; temp = temp->next)
    {
        printf("==PROCURANDO ELEMENTO==\n");
        if(temp->key == key) return temp;
    }
    return NULL;
}

int is_empty()
{
    return !head;
}

void remove_top()
{
    if(is_empty) return;
    no *temp = head;
    if(head != head->next)
    {
        head = head->next;
        aux->next = head;
    }
    else head = aux = NULL;
    free(temp);
}

int remove_middle(int key, int k_search)
{
    no *node = search(k_search);
    if(!node) return 1;
    //...
    
    
}

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

void print_elements()
{
    no *hd = head;
    no *fn = head;
    do
    {
        printf("%d\n", hd->key);
        hd = hd->next;

    }while(hd != fn);
    printf("===FIM DE LISTA===\n");
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
