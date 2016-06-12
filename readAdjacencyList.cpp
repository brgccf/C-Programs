#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<vector<ii> > con;

int main(){
	
	printf("digite o numero de vertices e o de arestas: \n");
	
	scanf("%d %d", &n, &m);
	con.resize(n+1);
	
	printf("digite as %d arestas neste formato: u v peso\n", m);
	
	for(int i = 0; i < m; ++i){
		int u, v, weight;
		scanf("%d %d %d", &u, &v, &weight);
		con[u].push_back(ii(weight, v));
		/* Se o grafo for bidirecional, cria tambem uma aresta de volta,
		 se nao for, apaga a linha debaixo */
		con[v].push_back(ii(weight, u)); 
	}
	
	printf("lista de adjacencia: U -> V (PESO)\n");
	for(int u = 0; u < n; ++u){
		for(int j = 0; j < con[u].size(); ++j){
			ii p = con[u][j];
			int weight = p.first;
			int v = p.second;
			printf("%d -> %d (%d)\n", u, v, weight);
		}
	}

    return 0;
}
