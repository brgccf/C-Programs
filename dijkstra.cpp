#include "bits/stdc++.h"
using namespace std;
#define INF 10001001
vector< vector<int> > dist; //guardar distancias descobertas aqui
vector< vector<int> > ant; //guardar antecessores aqui para pegar o caminho final

priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

void fill(int a, int b)
{
	for (int i = a; i < b; ++i)
	{
		for(int j = a; j < b)
		dist[i] = INF;
		ant[i] = 0;
	}
}

void dijkstra(int k)
{
	fill(1, k);

}

int main(int argc, char const *argv[])
{
		
	return 0;
}