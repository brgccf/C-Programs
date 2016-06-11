#include "bits/stdc++.h"
using namespace std;
#define INF 10001001
#define pb push_back


typedef struct node
{
	int key;
	int weight;
}node;

vector< vector<node> > dist; //guardar distancias descobertas aqui
vector<int> ant; //guardar antecessores aqui para pegar o caminho final


priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

void fill(int a, int b)
{
	//definindo parametros iniciais
	for (int i = a; i < b; ++i)
	{	
		for (int j = 0; j < dist[i].size(); ++j)
		{
			dist[i][j].weight = INF;
		}
	}

}

void dijkstra(int k)
{
	fill(1, 5);
	
}

int main(int argc, char const *argv[])
{
	int length;
	cin >> length;
	dist.resize(length+1);
	ant.resize(length+1);

	dist[1][0].key = 4;
	dist[1][1].key = 2;
	dist[1][2].key = 3;
	dist[2][0].key = 4;
	dist[3][0].key = 1;
	dist[3][1].key = 4;		

	for (int i = 0; i < length; ++i)
	{
		cout << i << " ";
		for (int j = 0; j < dist[i].size(); ++j)
		{
			cout << dist[i][j].key << " ";
		}
		cout << endl;
	}
	dijkstra(4); //4 eh o objetivo
	return 0;
}