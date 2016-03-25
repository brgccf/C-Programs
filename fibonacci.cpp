#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(int n)
{
	if(n == 0 || n == 1) return 1;
	else return fib(n-1) + fib(n-2);
}

/* ou:
unsigned long long fib(int n)
{
	unsigned long long a = 1, b = 1, c = 0;
	for(;n--;) { a = b + c; c = b; b = a; }
	return a;
}

*/

int main()
{
	int n = 4;
	unsigned long long sol;
}
