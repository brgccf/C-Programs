#include "bits/stdc++.h"
using namespace std;
typedef struct node
{
	int key;
	bool visited;
	node *next;
}node;

vector< vector<node> > vec; //lista de adjacencia

void DFS(int v)
{

}

int main(int argc, char const *argv[])
{
	printf("Digite a quantidade de valores\n");
	int n, limit;
	scanf("%d", &n);
	limit = n;
	--n;
	vec.resize(n, vector<node>( //num_of_row, int value));
	//criando vetor completo
	for (n; n > 0; --n)
	{
		vec[0][n] = n;
		printf("valor lido em vec[%d]: %d\n", n, vec[n]);
	}
	printf("n = %d\n", n);
	//colocando a lista dentro do vetor
	
	return 0;
}