/*Bruno Filho (brgccf)
UVa 11137 - Ingenuous Cube
*/
#include "bits/stdc++.h"
using namespace std;

// class tab
// {
// public:
// 	int key;
// 	bool belongs, exist;
// 	tab();
	
// };

// tab::tab()
// {

// }

typedef struct tab
{
	int key;
	bool belong, exist;
}tab;

int main(int argc, char const *argv[])
{

	vector<int> vec(22);
	for (int i = 1; i < 22; ++i)
	{
		int calc = i*i*i;
		vec[i] = calc; //linhas da tabela
		printf("%d\n", vec[i]);
	}

	tab table[21][9262]; //max == 9261
	table[0][0].key = 0;
	for(int i = 0; i < 21; ++i) table[0][i].exist = false;
	for (int i = 1; i < 21; ++i)
	{
		for (int j = 0; j < 9262; ++j)
		{

		}
	}
	printf("END\n");
	return 0;
}