#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class punt {
public:
	int n;
	int cp, tt;
	vector<bool> pp;
	vector<int> tiempo;
	punt(){ tiempo.resize(10, 0); pp.resize(10, false); n=0; cp=0; tt=0; }
	void contar(){
		//contar problemas resueltos y sus tiempos
		for (int i=1; i<=9; i++){
			if (pp[i]){ //resolví el problema i
				cp++;
				tt+=tiempo[i];
			}
		}		
	}
	bool operator<(const punt &otro) const {
		if (cp > otro.cp) return true;
		else if (cp < otro.cp) return false;
		else if (cp == otro.cp){ //misma cantidad de problemas, ver penalidades
			if (tt < otro.tt) return true;
			else if (tt > otro.tt) return false;
			else if (tt == otro.tt){ //misma penalidad, ver número de equipo
				if (n < otro.n) return true;
				else return false;
			}
		}
		return true;
	}

};

int main()
{
	map<int, punt> m;
	string s;
	int n;
	int c, p, t;
	char l;
	scanf("%i\n\n", &n);
	for (int i=0; i<n; i++){
		getline(cin, s);
		while (!s.empty()){
			stringstream ss(s);
			ss>>c>>p>>t>>l;
			map<int, punt>::iterator it = m.find(c);
			if (it == m.end()){
				m[c] = punt();
				it = m.find(c);
			}
			if (!(it->second.pp[p])){ //si no resolví el problema p...
				switch (l){
					case 'I':
						it->second.tiempo[p]+=20;
						break;
					case 'C':
						it->second.pp[p] = true;
						it->second.tiempo[p]+=t;
						break;
				}
			}
			getline(cin, s);
		} //termino de leer
		
		//mostrar resultados:
		
		//pasar los participantes a un vector
		map<int, punt>::iterator it = m.begin();
		vector<punt> part;
		while (it != m.end()){
			it->second.n = it->first;
			it->second.contar();
			part.push_back(it->second);
			it++;
		}
		
		//ordenarlos
		sort(part.begin(), part.end());
		
		//mostrar
		for (unsigned int i=0; i<part.size(); i++){
			if (part[i].cp) //si no resolvió ninguno, no mostrar
				cout<<part[i].n<<" "<<part[i].cp<<" "<<part[i].tt<<'\n';
		}
		
		cout<<'\n';
		m.clear();
	} //casos
	
	/*
	for (unsigned int i=0; i<v.size(); i++)
		cout<<v[i]<<'\n';
	*/
		
	return 0;
}
