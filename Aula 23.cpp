/* Aula 23 ---
--> PONTEIROS

EM C, PODEMOS ARMAZENAR O ENDEREÇO DA VARIÁVEL (É UM TIPO), QUE É O PONTEIRO.
Todos possuem o mesmo tamanho (para o compilador são todos iguais), mas possuem
tipos diferentes para ajudar o programador.

ex.: char *pch;
obs.: visualize como sendo 'char ponteiro' pch.

A quantidade de memória RAM do computador é proporcional ao tamanho do ponteiro.
O ideal é que este tamanho seja uma potência de 2.

Operador para encontrar o tamanho da memória em bytes ocupada por um ponteiro
sizeof(**tipo do ponteiro**);
- seu retorno é um size_t, que equivale a um unsigned int
ex.: sizeof(char*)

Utilizamos o '&' para encontrar o endereço de memória de uma variável e assim poder 
atribuir isto a um ponteiro.

Os ponteiros ocupam, via de regra, 8 bytes. Dessa forma, pode ser ruim 
para variáveis que ocupam pouca memória. Entretanto, são muito úteis quando
temos, por exemplo, um sistema de cadastro que possui 256 kbytes de memória.
é menos custoso para a memória alocar ponteiros em vez de criar cópias, neste caso.

obs.: utilizar sempre stdlib quando for usar ponteiros

