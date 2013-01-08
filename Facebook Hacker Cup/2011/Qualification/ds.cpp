#include <iostream>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

map<int, float> raices;

bool escuadrado(int r)
{
	map<int, float>::iterator it = raices.find(r);
	float raiz;
	if (it == raices.end()){
		pair< map<int, float>::iterator, bool> par = raices.insert(pair<int, float>(r, sqrt(r)));
		raiz = par.first->second;
	}
	else
		raiz = it->second;
	return (raiz - ceil(raiz) == 0);
}

void ds(int x)
{
	int cont = 0;
	int hasta = sqrt(x);
	for (int i=0; i <= hasta; ++i){
		int ii = i*i;
		int resto = x - ii;
		if (resto>=ii && escuadrado(resto))
			++cont;
	}
	cout<<cont<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, x;
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>x;
		ds(x);
	}
	return 0;
}
