#include <bits/stdc++.h>

int year, plus;
int bits[200];
int factorial_res[300000]; //pelo uDebug, o n maximo foi 254016

void generate_array()
{
	int i, counter = 4;
	for (i = 0; i < 200; ++i)
	{
		bits[i] = counter;
		counter += counter;
	}

}

int calculate_factorial(int a)
{
	if (a == 1) return 1;
	else if (factorial_res[a] != -1){
		return factorial_res[a];
	}
	else{
		factorial_res[a] = a * calculate_factorial(a-1);
		return factorial_res[a];
	}

}

int main(int argc, char const *argv[])
{
	memset(factorial_res, -1, sizeof(factorial_res));
	plus = 2;
	int result, position, qtd_bits, n = 3;
	generate_array();
	while(1){
		scanf("%d", &year);
		if (!year) break;
		position = ((year - 1960)/10);
		result = 0;
		printf("position = %d\n", position);
		qtd_bits = bits[position];
		int found = 0, fac;
		for (n = 3; n < 20; ++n)
		{
			fac = calculate_factorial(n);
			printf("fat de %d = %d\n", n, fac);
		}
		
	}
	return 0;
}