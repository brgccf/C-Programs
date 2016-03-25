/* Aula 23 ---
--> PONTEIROS

EM C, PODEMOS ARMAZENAR O ENDERE�O DA VARI�VEL (� UM TIPO), QUE � O PONTEIRO.
Todos possuem o mesmo tamanho (para o compilador s�o todos iguais), mas possuem
tipos diferentes para ajudar o programador.

ex.: char *pch;
obs.: visualize como sendo 'char ponteiro' pch.

A quantidade de mem�ria RAM do computador � proporcional ao tamanho do ponteiro.
O ideal � que este tamanho seja uma pot�ncia de 2.

Operador para encontrar o tamanho da mem�ria em bytes ocupada por um ponteiro
sizeof(**tipo do ponteiro**);
- seu retorno � um size_t, que equivale a um unsigned int
ex.: sizeof(char*)

Utilizamos o '&' para encontrar o endere�o de mem�ria de uma vari�vel e assim poder 
atribuir isto a um ponteiro.

Os ponteiros ocupam, via de regra, 8 bytes. Dessa forma, pode ser ruim 
para vari�veis que ocupam pouca mem�ria. Entretanto, s�o muito �teis quando
temos, por exemplo, um sistema de cadastro que possui 256 kbytes de mem�ria.
� menos custoso para a mem�ria alocar ponteiros em vez de criar c�pias, neste caso.

obs.: utilizar sempre stdlib quando for usar ponteiros

