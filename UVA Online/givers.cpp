//119 Greedy Gift Givers
//http://uva.onlinejudge.org/external/1/119.html
//Accepted
//C++ 0.008 2011-09-21 02:49:25

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n, caso=1;
	while (cin>>n){
		if (caso != 1) cout<<'\n';
		vector<string> nombres;
		map<string, int> m;
		string nom, otro;
		for (int i=0; i<n; ++i){
			cin>>nom;
			nombres.push_back(nom);
			m[nom] = 0;
		}
		int da, c;
		for (int i=0; i<n; ++i){ //ver qué hace cada uno
			cin>>nom>>da>>c;
			m[nom] -= da;
			int repartir, sobra = da;
			if (c != 0){
				repartir = da/c;
				sobra = da%c;
			}
			for (int j=0; j<c; ++j){ //repartir lo suyo a otros
				cin>>otro;
				m[otro] += repartir;
			}
			m[nom] += sobra;
		}
		//mostrar
		for (int i=0; i<nombres.size(); ++i)
			cout<<nombres[i]<<" "<<m[nombres[i]]<<'\n';
		caso++;
	}
	return 0;
}
