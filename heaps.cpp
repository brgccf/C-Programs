#include "bits/stdc++.h"
using namespace std;

void max_heapify(vector<int> heap, int n, int i) 
/*A é o array contendo os elementos
n é o número de elementos no array
i é o indice do nó raiz da sub-árvore considerada*/
{
	printf("===MAX-HEAPIFY===\n");
	int greater, temp;
	while(i <= n/2)
	{
		if(i < n/2)
		{
			if(heap[2*i] > heap[(2*i)+1]) greater = 2*i;
			else greater = (2*i)+1;
		}
		else greater = 2*i;
		if (heap[i] < heap[greater])
		{
			temp = heap[i];
			heap[i] = heap[greater];
			heap[greater] = temp;
			i = greater;
		}
		else i = n;
	}
}

void build_max_heap(vector<int> heap, int index)
{
	for (int i = index/2; i > 1; --i)
	{
		max_heapify(heap, 21, i);
	}
}

void print_heap(vector<int> heap, int n)
{
	printf("Actual heap:\n");
	for (int i = 1; i < n; ++i)
	{
		printf("%d", heap[i]);
		printf(" ");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	vector<int> heap(21); //capacidade de 20 elementos
	heap[0] = -1;
	print_heap(heap, 21);
	for (int i = 1; i < 21; ++i)
	{
		heap[i] = rand() % 100;
	}
	print_heap(heap, 21);
	max_heapify(heap, 21, 10);
	print_heap(heap, 21);
	
	return 0;
}