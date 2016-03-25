//-----Aula 2-----

/*
alguns atalhos de programação em C:
b = ++a
soma um em a e pega o valor somado atribuindo a b
b = a++
b recebe o valor anterior de a, enquanto este é incrementando em 1
cuidado:
b = (a++)
alguns compiladores interpretam como (a), logo retornará para b o valor de a já incrementado

o mesmo é válido para decremento (--)
b = --a
b = a--
b = (a--)

Alguns modos de impressao: exemplo numero 135
%5d --> __135 (da espaços onde não foi ocupado)
%7d --> ____135
%2d --> 135 (ignora o 2 e imprime o numero normalmente)
%05d --> 00135 (inclui zeros nos espaços vazios)

Pontos flutuantes: Quando dividimos numeros como 1/3 e não temos exatidao (flutuantes),
temos que levar consideração os possíveis erros, uma vez que o resultado desse tipo de operação
será aproximado, e não exato.
Para resolver isao, precisamos rever as operações e determinar uma margem de erro para o programa 
funcionar quando efetuar comparações entre tais pontos flutuantes

Em C temos como encontrar a exatidão : procurar por GMP

para imprimir flutuantes: %lf
Para imprimir flutuantes restringindo as casas decimais: %.3lf (imprime com 3 casas)


Problema:
dado um numero sendo de um certo ano, descubra se ele é bissexto
*Um ano é bissexto quando é divisível por 4, exceto quando é divisível por 100,
exceto quando também for divisível por 400
Problema 2:
Dados dois anos diferentes, retornar a quantidade de anos bissextos entre eles
*/


