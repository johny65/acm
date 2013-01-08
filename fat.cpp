#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct par {
	string nombre;
	int peso;
	bool operator < (par p) const {
		return (peso>p.peso);
	}
};

int main()
{
	vector<string> res;
	string l;
	cin>>l;
	while (l == "START"){
		vector<par> v;
		string n;
		cin>>n;
		while (n != "END"){
			int ddd, pi;
			cin>>ddd>>pi;
			par t;
			t.nombre = n;
			t.peso = pi-ddd;
			v.push_back(t);
			cin>>n;
		}
		sort(v.begin(), v.end());
		for (unsigned int i=0; i<v.size(); i++)
			res.push_back(v[i].nombre);
		res.push_back("-");
		v.clear();
		cin>>l;
	}
	//mostrar
	for (unsigned int i=0; i<res.size(); i++){
		if (res[i] == "-")
			cout<<'\n';
		else
			cout<<res[i]<<'\n';
	}
	
	return 0;
}
