/*---AULA 18 ---

Algoritmo Busca e Largura (Breadth-First Search) --> iterativo

--> algoritmo que lista todas as possibilidades de movimentacao e vai se movimentando, marcando os locais
que ja passou 
� como um for i ate n, por�m este n vai se alterando dentro do for dependendo das possibilidades

a recupera��o de passos ocorre de tras pra frente
--> utilizaremos uma fila para guardar as informa�oes dos passos:
nela, teremos as seguintes informa��es:
1) contagem dos passos anteriores � posicao analisada
2) contagem dos passos realizados ate a posicao analisada
3) coordenadas da posicao analisada
4) marcadores*
obs.: para determinar o tamanho da fila, precisamos calcular a quantidade de passos para alcan�ar nosso objetivo
*opcional Para evitar gastar muita memoria com isso , realize marca�oes nos elementos toda vez que forem adicionados na fila.
caso queiramos reutilizar o tabuleiro para outro processamento, podemos guardar as marca��es em outro array

if para verificar se ja chegou na solucao
if para verificar se o local esta marcado ou nao
