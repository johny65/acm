//Criba de Erat�stenes
//Para generar n�meros primos

/*
La criba de Erat�stenes es un algoritmo que permite
hallar todos los n�meros primos menores que un n�mero
natural dado N. Se forma una tabla con todos los n�meros
naturales comprendidos entre 2 y N y se van tachando
los n�meros que no son primos de la siguiente manera:
cuando se encuentra un n�mero entero que no ha sido
tachado, ese n�mero es declarado primo, y se procede
a tachar todos sus m�ltiplos. El proceso termina cuando 
el cuadrado del mayor n�mero confirmado como primo 
es mayor que N.
*/

#include <vector>
#include <iostream>

using namespace std;

// void criba(vector<bool> &b):
// genera todos los n�meros primos menores que N
// (usa b.size() como N)
// Todos los elementos de b deben ser true al inicio.
// Pone false a los n�meros que no son primos.
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
