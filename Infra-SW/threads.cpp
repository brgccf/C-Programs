#include "bits/stdc++.h"
#include "pthread.h"
using namespace std;

pthread_t threads[5]; //definindo 5 threads

void *thread_func(void *arg)
{

}
/*
Cria uma nova thread com ID único, que executa uma rotina 
assim que criada e passa um único argumento para essa rotina
attr e arg podem ser NULL 
*/
int pthread_create(pthread_t *thread, 
	const pthread_attr_t *attr, 
	void* (*start_routine)(void *), void *arg);

int main(int argc, char const *argv[])
{
	int groups, peop;
	cout << "Digite a quantidade de grupos" << "\n";
	scanf("%d", &groups);
	cout << "Digite a quantidade de integrantes por grupo:" << "\n";
	scanf("%d", &peop);
	int mdc [groups][peop][5];
	printf("%ld\n", sizeof(mdc));
	return 0;
}