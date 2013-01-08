//Criba de Eratóstenes
//Para generar números primos

/*
La criba de Eratóstenes es un algoritmo que permite
hallar todos los números primos menores que un número
natural dado N. Se forma una tabla con todos los números
naturales comprendidos entre 2 y N y se van tachando
los números que no son primos de la siguiente manera:
cuando se encuentra un número entero que no ha sido
tachado, ese número es declarado primo, y se procede
a tachar todos sus múltiplos. El proceso termina cuando 
el cuadrado del mayor número confirmado como primo 
es mayor que N.
*/

#include <vector>
#include <iostream>

using namespace std;

// void criba(vector<bool> &b):
// genera todos los números primos menores que N
// (usa b.size() como N)
// Todos los elementos de b deben ser true al inicio.
// Pone false a los números que no son primos.
void criba(vector<bool> &b)
{
	for (int i = 2; i*i <= b.size(); ++i){
		if(b[i]){
			for(int h = 2; i*h <= b.size(); ++h)
				b[i*h] = false;
		}
	}
}

//para mostrar
int main()
{
	int n; cin>>n;
	vector<bool> b(n, true);
	criba(b);
	for (int i=2; i<b.size(); i++)
		if (b[i]) cout<<i<<'\n';
	return 0;
}
