/*----AULA 3----

PROBLEMA 1:
QUAL SERAH O DIA DA SEMANA DAQUI A N DIAS (Futuro)? 


PROBLEMA 2:
QUAL FOI O DIA DA SEMANA HA N DIAS ATRAS (Passado)?



SOLU��O: Considerando dia atual ter�a feira
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
--> define uma constante na pr� compila��o. Antes mesmo do codigo compilar, onde
houver escrito TAM , ser� substituido por 3.

*Operador tern�rio:
int a = 3, b = 7;
int m = (a > b)? a : b;
--> se for verdade, retorna a, se n�o, retorna b.

*O comando typedef :
� semelhante a uma classe. Podemos definir alguns par�metros e refenci�-los com uma
palavra-chave de nossa escolha.
Exemplo: Datas
typedef struct
{
	int dia;
	int mes;
	int ano;
} Data;

PROBLEMA 3 Levar efici�ncia em considera��o: Hard
Temos uma data como entrada (assuma que seja v�lida) (ex: 4 Julho 1776)
Informar qual � o dia da semana da data informada!

PROBLEMA 4:
Temos um tabuleiro
n < 2 bilhoes
O objeto se movimenta com um padr�o de movimenta��o (desafio da lista 3 - Java)



*/
