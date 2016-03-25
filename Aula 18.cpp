/*---AULA 18 ---

Algoritmo Busca e Largura (Breadth-First Search) --> iterativo

--> algoritmo que lista todas as possibilidades de movimentacao e vai se movimentando, marcando os locais
que ja passou 
é como um for i ate n, porém este n vai se alterando dentro do for dependendo das possibilidades

a recuperação de passos ocorre de tras pra frente
--> utilizaremos uma fila para guardar as informaçoes dos passos:
nela, teremos as seguintes informações:
1) contagem dos passos anteriores à posicao analisada
2) contagem dos passos realizados ate a posicao analisada
3) coordenadas da posicao analisada
4) marcadores*
obs.: para determinar o tamanho da fila, precisamos calcular a quantidade de passos para alcançar nosso objetivo
*opcional Para evitar gastar muita memoria com isso , realize marcaçoes nos elementos toda vez que forem adicionados na fila.
caso queiramos reutilizar o tabuleiro para outro processamento, podemos guardar as marcações em outro array

if para verificar se ja chegou na solucao
if para verificar se o local esta marcado ou nao
