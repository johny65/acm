#include <iostream>

using namespace std;

class nodo {
public:
	fraccion *v;
	nodo *izq, *der;
};

class fraccion {
public:
	int num, den;
	fraccion(int n, int d) : num(n), den(d) {};
	double valor(){ return 1.0*num/den; };
};

int main()
{
	int m, n;
	scanf("%d %d\n", &m, &n);
	while (m != 1 || n != 1){
		fraccion f(m, n);
		sacar(f);
		scanf("%d %d\n", &m, &n);
	}
	return 0;
	
}
