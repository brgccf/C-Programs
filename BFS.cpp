#include "bits/stdc++.h"
using namespace std;

vector< vector<int> > vec;
vector<bool> marked;
queue<int> que;

//toma um vertice qualquer
void BFS(int node, int parent)
{
	que.push(node);
	while(!que.empty()) //enquanto fila nao estiver vazia
	{
		node = que.front(); //primeiro elemento
		marked[node] = true;
		que.pop();
		for (int i = 0; i < vec[node].size(); ++i) //para toda aresta (node,w) incidente a node
		{
			int w = vec[node][i];
			if (!marked[w]) //se w nao marcado
			{
				parent = node; //definindo o pai
				que.push(w); //aresta de arvore
			}
			else
			{
				if (node == parent) //parent deve ser pai de w
				{
					//aresta de arvore
					return;
				}
				else{
					//aresta de cruzamento
					continue;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}