#include <iostream>
#include <vector>

using namespace std;

void calcular(vector<int> &v, int cont, int n)
{
	
	/*cout<<"Datos:\n";
	for (int i=0; i<cont; i++)
		cout<<v[i]<<'\n';
	*/
	
	vector<bool> b(n, false);
	for (int i=0; i<cont; i++){ //reviso cada h
		int inc = v[i];
		for (int j=inc; j<=n; j+=inc){
			b[j-1] = true;
		}
	}
	
	//contar
	//no hay hartals los sábados -> no puede ser múltiplo de 7
	//no hay hartals los viernes -> no puede ser múltiplo de 7 el i+1
	for (int i=6; i<=n; i+=7){
		b[i] = false;
		b[i-1] = false;
	}
	
	int suma=0;
	for (int i=0; i<n; i++){
		if (b[i])
			suma++;
	}
	
	/*
	for (int i=0; i<n; i++)
		cout<<i+1<<" "<<b[i]<<'\n';
	*/
		
	cout<<suma<<'\n';
}


int main()
{
	vector<int> strikes(100);
	int cont=0;
	int t, n, p;
	cin>>t;
	for (int i=0; i<t; i++){ //casos
		scanf("%i\n%i\n", &n, &p);
		for (int j=0; j<p; j++){
			int t;
			scanf("%i\n", &t);
			strikes[j] = t;
			cont++;
		}
		calcular(strikes, cont, n);
		cont=0;
	}
	
	return 0;
}
