//Criba de Sundaram
//Para generar números primos

#include <vector>
#include <iostream>

using namespace std;

// void criba(vector<bool> &b):
// genera todos los números primos hasta 2*N
// (usa b.size() como N)
// Todos los elementos de b deben ser true al inicio.
// Pone false a los números que no son primos.
void criba(vector<bool> &b)
{
	for (int j=1;;++j) {
		int k=1+3*j;
		if (k>=b.size())
			break;
		do {
			b[k] = false;
			k += 2*j+1;
		} while (k<b.size());
	}
}

//para mostrar
int main()
{
	int n; cin>>n;
	vector<bool> b(n, true);
	criba(b);
	cout<<2<<'\n'; //no genera el 2
	for (int i=1; i<b.size(); ++i)
		if (b[i]) cout<<(2*i+1)<<'\n';
	return 0;
}
