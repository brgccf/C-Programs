#include "bits/stdc++.h"
using namespace std;
#define INF 10001001
#define pb push_back
typedef pair<int,int> ii;

vector<int> dist; //guardar distancias descobertas aqui
vector<int> ant; //guardar antecessores aqui para pegar o caminho final
vector< vector<ii> > graph;
/*
obs> pair<int,int> o primeiro int é o peso e o segundo eh o node
assim, se con[u] = {(1,2),(3,4),(2,5)}
entao o vertice U está conectado 
com os vertices 2, 4 e 5, com arestas de peso 1, 3 e 2, respectivamente
*/
priority_queue< ii, vector< ii >, greater< ii > > pq;

inline void fill(int n) //n = nvert
{
	//definindo parametros iniciais
	//printf("GOT INSIDE FILL\n");
	for (int i = 0; i < n; ++i)
	{
		dist[i] = INF;
		ant[i] = INF;
	}
	ant[0] = -1;
}

void print_state(int nver)
{
	cout << "distances: ";
	for (int i = 0; i < nver; ++i)
	{
		cout << dist[i] << " ";
	}
	cout << endl;
	cout << "antecessors: ";
	for (int i = 0; i < nver; ++i)
	{
		cout << ant[i] << " ";
	}
	cout << endl;
}

void dijkstra(int nver, int base)
{
	//fill
	dist[base-1] = 0; //base
	pq.push(ii(dist[base-1], base)); //1 eh a raiz
	while(!pq.empty())
	{
		ii actual = pq.top();
		// printf("actual == %d\n", actual.second);
		pq.pop(); //marca actual
		for (int i = 0; i < graph[actual.second].size(); ++i)
		{
			ii adj = graph[actual.second][i];
			if((dist[actual.second-1] + adj.first) < dist[adj.second-1])
			{
				dist[adj.second-1] = dist[actual.second-1] + adj.first;
				pq.push(ii(dist[adj.second-1], adj.second));
				ant[adj.second-1] = actual.second;
			}
			// printf("adj == %d\n", adj.second);
		}
		printf("\n");
		print_state(nver);
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int nvert, nares, count = 1;
	do{
		cin >> nvert >> nares;
		if(nvert == 0 || nares == 0) break;
		graph.resize(nvert+1);
		dist.resize(nvert);
		ant.resize(nvert);

		for (int i = 0; i < nares; ++i)
		{
			int u, v, weight;
			cin >> u >> v >> weight;
			graph[u].pb(ii(weight, v)); //u aponta para v com peso weight
			graph[v].pb(ii(weight, u)); //grafo bidirecionado
		}
		fill(nvert);
		dijkstra(nvert, 1);
		int c = 1;
		for (int i = 1; i < ant.size(); ++i)
		{
			int a = ant[i];
			
		}
		printf("Teste %d\n", count);
		for (int i = 1; i < ant.size(); ++i)
		{
			printf("%d %d\n", ant[i], i+1);
		}
		++count;
	}while(1);

	return 0;
}