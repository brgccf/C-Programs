#include "bits/stdc++.h"

int last_state = 0, ant_m;

void game(int numb_stones, int array[], int m)
{
	while(numb_stones >= 0)
	{
		printf("numb_stones == %d\n", numb_stones);
		numb_stones -= array[last_state];
		if(numb_stones >= 0) ++last_state;
		if(last_state > (m-1)) last_state = 0;
	}
}

int main(int argc, char const *argv[])
{
	//DEVE PEGAR O ULTIMO VALOR QUE SUBTRAIU E USAR COMO PROX VALOR
	//PARA SUBTRAIR NO PROX CASO
	int numb_stones;
	int m;
	while(scanf("%d %d", &numb_stones, &m) != EOF)
	{
		int array[m];
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &array[i]);
			//printf("arrau[%d] == %d\n", i, array[i]);
		}
		game(numb_stones, array, m);
		if(last_state%2) printf("Ollie wins\n");
		else printf("Stan wins\n");
		printf("last_state == %d\n", last_state);
		ant_m = m;
	}
	return 0;
}