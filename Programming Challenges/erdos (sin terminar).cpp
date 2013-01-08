#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

map<string, int> mapa;
vector<string> nombres;
vector< vector<string> > v;

void separarnombres(string &s) //mete los nombres en nombres
{
	nombres.clear();
	int p;
	string t;
	while (true){
		p = s.find(',', 0);
		p = s.find(',', p+1);
		t = s.substr(0, p);
		if (t == "Erdos, P.") t = "E";
		nombres.push_back(t);
		if (p == string::npos) break;
		s = s.substr(p+2, s.length());
	}
}

void filtro(vector<bool> &vb)
{
	for (int i=0; i<v.size(); i++){
		//v[i] es un vector<string>
		bool erdos = false;
		if (find(v[i].begin(), v[i].end(), "E") != v[i].end()){
			//está erdos en la lista, poner 1 a todos
			for (int j=0; j<v[i].size(); j++){
				if (v[i][j] != "E") mapa.insert(pair<string, int>(v[i][j], 1));
			}
			vb[i] = true;
		}
	}
}

void sacarnumerosdeerdos(vector<string> nombres2, bool erdos)
{
	int min = INT_MAX;
	if (!erdos) { //no está erdos en la lista
		for (int i=0; i<nombres2.size(); i++){ //reviso cada autor
			map<string, int>::iterator itt = mapa.find(nombres2[i]);
			if (itt == mapa.end() || itt->second == -1){ //este autor todavía no tiene número de erdos
				for (int j=0; j<nombres2.size(); j++){
					if (j!=i){
						map<string, int>::iterator it = mapa.find(nombres2[j]);
						if (it != mapa.end()){
							int nt = it->second;
							if (nt > 0 && nt < min) min=nt;
						}
					}
				}
				if (min == INT_MAX) min=-2;
				mapa[nombres2[i]] =  min+1;
			}
		}
	}
}

void calcular(vector<bool> &vb)
{
	for (int i=0; i<v.size(); i++){
		sacarnumerosdeerdos(v[i], vb[i]);
	}
}

int main()
{
	int s;
	scanf("%i\n", &s);
	int p, n;
	string temp, basura;
	for (int i=0; i<s; i++){ //casos
		scanf("%i %i\n", &p, &n);
		vector<string> listanombres(n);
		for (int j=0; j<p; j++){ //papers
			getline(cin, temp, ':');
			getline(cin, basura, '\n');
			separarnombres(temp);
			v.push_back(nombres);
		}
		for (int j=0; j<n; j++){ //nombres
			getline(cin, temp);
			listanombres[j] = temp;
		}
		
		vector<bool> vb(v.size(), false);
		filtro(vb);
		calcular(vb);
		calcular(vb);
		
		/*
		for (map<string, int>::iterator it=mapa.begin(); it!=mapa.end(); it++){
			cout<<it->first<<" : "<<it->second<<'\n';
		}
		*/
		
		
		//salida
		cout<<"Scenario "<<i+1<<'\n';
		for (int j=0; j<listanombres.size(); j++){
			int num = mapa[listanombres[j]];
			cout<<listanombres[j]<<" ";
			if (num == -1) cout<<"infinity\n";
			else cout<<num<<'\n';
		}
		
		v.clear();
		mapa.clear();
	
	}
	return 0;
}
