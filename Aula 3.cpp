/*----AULA 3----

PROBLEMA 1:
QUAL SERAH O DIA DA SEMANA DAQUI A N DIAS (Futuro)? 


PROBLEMA 2:
QUAL FOI O DIA DA SEMANA HA N DIAS ATRAS (Passado)?



SOLUÇÃO: Considerando dia atual terça feira
char dia_da_semana[7][20] = {"domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};

void imprimir_dia(int n)
{
if( n >= 0 && n <= 6) printf ("%s\n", dias_da_semana[n]);
else printf("invalido"\n);
}

void dia_futuro(int n, int k){
imprimir_dia((n + k)%7);
}

void dia_passado(int n, int k)
{
imprimir_dia ((n + 7 - (k % 7)) % 7);
}

int main()
{
	int n = 2;
	dia_passado(n, 7);
	dia_futuro(n, 8);
	return 0;
}

---------
#define TAM 3
--> define uma constante na pré compilação. Antes mesmo do codigo compilar, onde
houver escrito TAM , será substituido por 3.

*Operador ternário:
int a = 3, b = 7;
int m = (a > b)? a : b;
--> se for verdade, retorna a, se não, retorna b.

*O comando typedef :
é semelhante a uma classe. Podemos definir alguns parâmetros e refenciá-los com uma
palavra-chave de nossa escolha.
Exemplo: Datas
typedef struct
{
	int dia;
	int mes;
	int ano;
} Data;

PROBLEMA 3 Levar eficiência em consideração: Hard
Temos uma data como entrada (assuma que seja válida) (ex: 4 Julho 1776)
Informar qual é o dia da semana da data informada!

PROBLEMA 4:
Temos um tabuleiro
n < 2 bilhoes
O objeto se movimenta com um padrão de movimentação (desafio da lista 3 - Java)



*/
