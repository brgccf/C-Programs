#include "bits/stdc++.h"
using namespace std;

vector<int> heap(11); //capacidade de 10 elementos

void max_heapify(int n, int i) 
/*A é o array contendo os elementos
n é o número de elementos no array
i é o indice do nó raiz da sub-árvore considerada*/
{
	printf("===MAX-HEAPIFY===\n");
	printf("n == %d\ni == %d\n", n, i);
	int greater, temp;
	while(i <= n/2)
	{
		if(i < (n+1)/2)
		{
			if(heap[2*i] > heap[(2*i)+1]) greater = 2*i;
			else greater = (2*i)+1;
		}
		else greater = (2*i);
		if (heap[i] < heap[greater])
		{
			printf("greater == %d\n", greater);
			temp = heap[i];
			heap[i] = heap[greater];
			heap[greater] = temp;
			i = greater;
		}
		else i = n;
	}
}

void build_max_heap(int index)
{ 
	for (int i = index/2; i > 0; i--)
	{
		max_heapify(index, i);
	}

}

void min_heapify(int n, int i)
{
	printf("===MIN HEAPIFY===\n");
	printf("n == %d\ni == %d\n", n, i);
	int smaller, temp;
	while(i <= n/2)
	{
		if (i < (n+1)/2)
		{
			if(heap[i*2] < heap[(2*i)+1]) smaller = 2*i;
			else smaller = (2*i)+1;
		}
		else smaller = 2*i;
		if (heap[i] > heap[smaller])
		{
			temp = heap[i];
			heap[i] = heap[smaller];
			heap[smaller] = temp;
			i = smaller;
		}
		else i = n;
	}
}

inline void build_min_heap(int index)
{
	//heap[index] = key;
	for (int i = index/2; i > 0; i--)
	{
		min_heapify(index, i);
	}
}

void print_heap(int n)
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
	//vector<int> heap(11); //capacidade de 20 elementos
	heap[0] = -1;
	int key;
	print_heap(11);
	for (int i = 1; i < 11; ++i)
	{
		key = rand() % 100;
		printf("KEY = %d\n", key);
		heap[i] = key;
		print_heap(11);
	}
	build_min_heap(10);
	//print_heap(heap, 11);
	//max_heapify(heap, 11, 10);
	printf("FINISH:\n");
	print_heap(11);

	// int ch;
	// printf("Print min_heap?\n");
	// scanf("%d", &ch);
	// if(ch == 1)
	// {
	// 	build_min_heap(5, key);
	// 	print_heap(11);
	// }
	
	return 0;
}