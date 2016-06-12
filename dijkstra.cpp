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

void dijkstra(int nver)
{
	//fill
	dist[0] = 0; //base
	for (int i = 0; i < nver; i++) //experimenta botar +1 apos nver
	{
		printf("GRAPH[%d] == %d\n", i, graph[i].size());
		for (int j = 0; j < graph[i].size(); j++)
		{
			ii adj = graph[i][j]; //vertice adjacente
			int wei = adj.first; //custo de u -> v
			int no = adj.second; //node sendo analisado
			cout << "no = " << no << endl;
			cout << "wei = " << wei << " " << dist[i] << endl;
			if((dist[i] + wei) < dist[no-1]) 
			{
				//cout << "get inside if!" << endl;
				dist[no-1] = dist[i] + wei; //atualiza distancia
			}
		}
	}
	print_state(nver);
}

int main(int argc, char const *argv[])
{
	int nvert, nares;
	cin >> nvert >> nares;
	graph.resize(nvert+1);
	dist.resize(nvert);
	ant.resize(nvert);

	cout << "lendo arestas em formato u v peso" << endl;

	for (int i = 0; i < nares; ++i)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		graph[u].pb(ii(weight, v)); //u aponta para v com peso weight
		graph[v].pb(ii(weight, u)); //grafo bidirecionado
	}

	//imprimindo resultado
	cout << "Graph read: " << endl;
	for (int i = 0; i < nares; ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			ii p = graph[i][j];
			int w = p.first;
			int v = p.second;
			printf("%d -> %d (%d)\n", i, v, w);
		}
	}

	fill(nvert);
	dijkstra(nvert);

	return 0;
}