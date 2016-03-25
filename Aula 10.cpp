/*
AULA 10 
*Estudar Permutações em C!

Escrevendo strings:
Toda string DEVE ser delimitada por um 0 no final! --> 0, '\0', NULL --> todos esses funcionam como delimitadores
Biblioteca <string.h>

devemos implementar as funções:
1)strlen --> dá o tamanho da string
--> int l = strlen(s); (decobre onde tem um zero na string)

2)strcat --> concatena Strings
	
-> char t[40]; //t[0] = '\0';
	strcat(t, "string: "); //concatena o texto a t;
	strcat(t, s)


3) strcpy --> concatena sobrepondo as strings (como uma atribuição)


4) strcmp --> compara as strings. (basicamente A - B)
Se as strings forem iguais, retornará zero.

Entrada e saída:
sscanf --> lê de uma string e atribui a uma variável
exemplo:
char premio[] = "83.756";
doulble d;
sscanf(premio, "%lf", &d);
//d = 83,756

lendo do teclado: scanf("%s", string); // nao precisa de &

sprintf --> possibilita a atribuição de uma string e até imprimir números diferentes na mesma string
exemplo: count = 2 
char file_name[50];
sprintf(file_name, "arq_%d", count);


DÚVIDA: Como inicializar um array de char (string) com o tamanho da entrada do teclado e atribuir a entrada à string criada ao mesmo tempo?
*/
