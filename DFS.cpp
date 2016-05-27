#include "bits/stdc++.h"
using namespace std;
/* 
	***DEPTH-FIRST SEARCH***
	Busca em profundidade
*/
typedef struct node
{
	int key;
	bool visited;
}node;

vector< vector<node> > vec; //lista de adjacencia

void DFS(node no, node parent)
{
	no.visited = true;
	printf("===Marked: %d===\n", no.key);
	for (int i = 0; i < vec[no.key].size(); ++i) //para toda aresta (v,w) incidente a v
	{
		node w = vec[no.key][i];
		if (!w.visited)//se w nao estiver marcado
		{
			parent = no; //pai passa a ser o no anterior
			//w eh o filho
			DFS(w, parent);
		}
		else //se w esta marcado
		{
			if (w.key != parent.key) //se nao for o pai
			{
				printf("RETORNOU\n");
				return; //aresta de retorno
			}
			else 
			{
				printf("CRUZAMENTO\n");
				//aresta de cruzamento
				continue;
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vec.resize(n); //seta o tamanho da lista

	for(int i=0;i<9;++i) {
		int X, Y;
		cin >> X >> Y;
		node a, b;
		a.key = X;
		a.visited = false;
		b.key = Y;
		b.visited = false;
		vec[X].push_back(b); 
		vec[Y].push_back(a); //grafo bidirecionado
	}
	//temos n² ligaçoes possiveis entre cada no, dado que 0->1 e 1->0

	for(int i=0;i<n;++i) {
		cout << i << " ";
		for(int j=0;j<vec[i].size();++j) {
			cout << vec[i][j].key << " ";
		}
		cout << endl;
	}

	//DFS:
	printf("DFS:\n");
	//printf("%s\n", vec[1][0].visited ? "true" : "false");
	DFS(vec[0][0], vec[0][0]);
	
	return 0;
}