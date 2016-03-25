/*
--AULA 24 --- 
PONTEIROS

>> Escopos
- Smepre ao final de um escopo, o compilador automaticamente deleta as variaveis
criadas ali dentro

Aloca��o de Matriz din�mica
c�digo para armazenar um array de ponteiros de tamanho n?
int **a;
a = (int**) malloc(sizeof(int*)*n);

//sendo uma matriz n x m ; precisaremos utilizar n mallocs (aloca��es de memoria)
//de tamanho m.

for(i = 0; i < n; i++) a[i] = (int*) malloc (m*sizeof(int));

//lembrar de liberar memoria:
for(i = 0; i < n; i++) free(a[i]);
free(a);
