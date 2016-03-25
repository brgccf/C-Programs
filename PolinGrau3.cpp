#include <stdio.h>
#include <math.h>

#define EPS 10e-9

//F(x) = Ax³ + Bx² + Cx + D = 0	 -----> encontre a raiz
//obs.: f(a) * f(b) < 0
//intervalos possiveis: [-inf, x1] ; [x1, x2] ; [x2, +inf]

double a, b;
double A, B, C, D;

int read_data()
{
	printf("Defina os coeficientes:\n");
	scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
	printf("Coeficientes definidos. Defina o intervalo [a, b]: \n");
	scanf("%lf%lf", &a, &b);
}


double f(double x)
{
	return ((A*x + B)*x + C)*x + D;
}

/*
double busca(double a, double b)
{
	if(fabs(a-b) < EPS) return (a+b)/2;
	double m = (a+b)/2;
	if(f(m) * f(b) < 0) return busca(m, b);
	return busca(a, m);
}
*/

double busca_binaria(double a, double b)
{
	if(fabs(a-b) < EPS) return (a+b)/2;
	double m = (a + b)/2;
	double fa = f(a);
	double fb = f(b);
	double fm = f(m);
	if(fm * fb < 0) return busca_binaria(m, b);
	else return busca_binaria(a, m);
}

double process(double x, double z)
{
	
	double root = busca_binaria(x, z);
	return root;		
	
	/*
	double root = busca(x, z);
	return root;
	*/
}

double procura_raizes(double root)
{
	double inf_pos = root + 500;
	double inf_neg = root - 500;
	double raiz_maior = busca_binaria(root, inf_pos);
	double raiz_menor = busca_binaria(root, inf_neg);
	printf("Raiz maior: %lf\nRaiz Menor: %lf\n", raiz_maior, raiz_menor);
	
}


int main()
{
	read_data();
	double result = process(a, b);
	printf("Raiz: %lf\n", result);
	procura_raizes(result);
	return 0;
}
