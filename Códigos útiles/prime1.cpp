#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

unsigned int ultimo;

vector<unsigned int> p;

bool esprimo(unsigned int n){
	if (n == 1) return false;
	if (n == 2) return true;
	for (unsigned int i=2; i<=sqrt(n); i++){
		if (n%i == 0) return false;
	}
	return true;
}

void primos(unsigned int m, unsigned int n)
{
	//buscar un primo siguiendo a m
	int i;
	for (i=0; i<p.size(); i++)
		if (p[i] >= m) break; //encontró
	
	//mostrar hasta los que haya
	unsigned int ultimo=m-1;
	for (int j=i; j<p.size(); j++){
		if (p[j] <= n){
			cout<<p[j]<<'\n';
			ultimo = p[j]; //me fijo cuál es el último
		}
		else { //llegó a mostrar todos
			ultimo = n;
			cout<<'\n';
		}
	}
	
	if (ultimo == n) return; //ya están todos
	
	//sino seguir generando primos
	for (unsigned int k=ultimo+1; k<=n; k++){
		if (esprimo(k)){
			cout<<k<<'\n';
			p.push_back(k); //lo guardo
		}
	}
	
	sort(p.begin(), p.end());
	cout<<'\n';
	return;
}

void pb(vector<bool> &v)
{
	for (unsigned int k=1; k<=v.size(); k+=2){
		if (esprimo(k)){
			v[k-1] = true;
		}
	}
	
}

void criba(vector<bool> &b)
{
	for(int i = 2; i*i <= b.size(); ++i)
		if(b[i])
			for(int h = 2; i*h <= b.size(); ++h)
				b[i*h] = false;

}

void p2(int m, int n, vector<bool> &b)
{
	int N = n+1, u2;
	for(int i = 2; i*i <= N; ++i){
		if(b[i]){
			for(int h = 2; i*h <= N; ++h){
				b[i*h] = false;
			}
		}
	}

	for (int i=m; i<N; i++)
		if (b[i]) cout<<i<<'\n';
	cout<<'\n';
	return;
}


int main()
{
/*
	//vector<bool> b(1000000, false); //para pb
	vector<bool> b(1000000000, true); //para criba
	cout<<"Calculando...\n";
	//pb(b);
	criba(b);
	cout<<"Listo.\n";
*/	
	vector<bool> b(1000000000, true);
	b[0] = false;
	b[1] = false;
	unsigned int m, n;
	ultimo = 2;
	int c;
	cin>>c;
	//casos
	for (int i=0; i<c; i++){
		cin>>m>>n;
		p2(m, n, b);
		ultimo = n;
	}

	return 0;
		
}
