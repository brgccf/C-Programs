/*
--- AULA 15 ----
algoritmo para calcular exponencial em log n
int exp (int a, int b)
{
	if(b==0) return 1;
	int v = exp(a,b/2);
	if(b%2)return a*v*v;
	else return v*v;
}


*/
