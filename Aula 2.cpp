//-----Aula 2-----

/*
alguns atalhos de programa��o em C:
b = ++a
soma um em a e pega o valor somado atribuindo a b
b = a++
b recebe o valor anterior de a, enquanto este � incrementando em 1
cuidado:
b = (a++)
alguns compiladores interpretam como (a), logo retornar� para b o valor de a j� incrementado

o mesmo � v�lido para decremento (--)
b = --a
b = a--
b = (a--)

Alguns modos de impressao: exemplo numero 135
%5d --> __135 (da espa�os onde n�o foi ocupado)
%7d --> ____135
%2d --> 135 (ignora o 2 e imprime o numero normalmente)
%05d --> 00135 (inclui zeros nos espa�os vazios)

Pontos flutuantes: Quando dividimos numeros como 1/3 e n�o temos exatidao (flutuantes),
temos que levar considera��o os poss�veis erros, uma vez que o resultado desse tipo de opera��o
ser� aproximado, e n�o exato.
Para resolver isao, precisamos rever as opera��es e determinar uma margem de erro para o programa 
funcionar quando efetuar compara��es entre tais pontos flutuantes

Em C temos como encontrar a exatid�o : procurar por GMP

para imprimir flutuantes: %lf
Para imprimir flutuantes restringindo as casas decimais: %.3lf (imprime com 3 casas)


Problema:
dado um numero sendo de um certo ano, descubra se ele � bissexto
*Um ano � bissexto quando � divis�vel por 4, exceto quando � divis�vel por 100,
exceto quando tamb�m for divis�vel por 400
Problema 2:
Dados dois anos diferentes, retornar a quantidade de anos bissextos entre eles
*/


