#include "bits/stdc++.h"
using namespace std;

typedef struct node
{
	int key;
	bool visited;
}node;

vector< vector<int> > vec; //lista de adjacencia

void DFS(int v)
{

}

int main(int argc, char const *argv[])
{
	printf("Digite a quantidade de valores\n");
	int n;
	scanf("%d", &n);
	vec.resize(n);

	for(int i=0;i<=n;++i) {
		int X, Y;
		cin >> X >> Y;
		vec[X].push_back(Y);
		vec[Y].push_back(X);
	}

	for(int i=0;i<n;++i) {
		cout << i << " ";
		for(int j=0;j<vec[i].size();++j) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}