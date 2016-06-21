/*Bruno Filho (brgccf)
UVa 11137 - Ingenuous Cube
*/
#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long int b64;
#define max 10000
b64 tab[max];
int main(int argc, char const *argv[])
{

	vector<int> coi(22);
	for (int i = 1; i < 22; ++i)
	{
		int calc = i*i*i;
		coi[i] = calc; //linhas da tabela
		//printf("%d\n", vec[i]);
	}
	int read;
	while(scanf("%d", &read) == 1)
	{
		for (int i = 0; i < max; ++i) tab[i] = 0;
		tab[0] = 1;
		for (int i = 1; i < 22; ++i)
		{
			for (int j = coi[i]; j <= read; ++j)
			{
				tab[j] = tab[j] + tab[j-coi[i]];
			}
		}
		printf("%llu\n", tab[read]);
	}

	//printf("END\n");
	return 0;
}