#include "bits/stdc++.h"

using namespace std;
vector< vector<int> > vec(1); //lista de adjacencia

typedef struct node
{
	int key;
	bool visited;
	node *next;
}node;

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
	vec.resize(n);
	//criando vetor completo
	for (n; n > 0; --n)
	{
		vec[n] = n;
		printf("valor lido em vec[%d]: %d\n", n, vec[n]);
	}
	printf("n = %d\n", n);
	//colocando a lista dentro do vetor
	for(n; n < limit; ++n)
	{
		printf("Digite a qtd vizinhos de %d\n", vec[n]);
		int viz;
		scanf("%d", &viz);

		printf("Digite quem sao os vizinhos\n");
		int qm;
		for(viz; viz > 0; --viz)
		{
			node *novo = (node*) malloc(sizeof(node));
			scanf("%d", &qm);
			novo->key = qm;
			novo->visited = false;
			novo->next = NULL;
		}

	}

	return 0;
}