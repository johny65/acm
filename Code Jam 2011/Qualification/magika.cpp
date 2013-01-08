#include <iostream>
#include <map>
#include <string>


using namespace std;

//long abinario (long num){
//	if (num < 2){
//		return num;
//	}
//	else {
//		return num%2 + ( 10 * abinario (num/2));
//	}
//}

void invoke(string &lista, map<string, char> &comb, map<char, char> &opos, int caso)
{
	int i=1;
	while (i<lista.length()){
		string par = lista.substr(i-1, 2);
		map<string, char>::iterator it = comb.find(par);
		if (it != comb.end()){ //combinación
			lista.replace(i-1, 2, 1, it->second);
			continue;
		}
		map<char, char>::iterator it2 = opos.find(lista[i]);
		if (it2 != opos.end()){ //tiene un opuesto
			//ver si está ese opuesto en la lista
			if (lista.substr(0, i).find(it2->second) != string::npos){
				//vacío lista
				lista = lista.substr(i+1);
				i = 1;
				continue;
			}
		}
		i++;
	}
	if (lista.length() == 0)
		cout<<"Case #"<<caso<<": []\n";
	else {
		cout<<"Case #"<<caso<<": [";
		for (int i=0; i<lista.length()-1; ++i){
			cout<<lista[i]<<", ";
		}
		cout<<lista[lista.length()-1]<<"]\n";
	}
}

int main() {
	int t;
	int c, d, n;
	cin>>t;
	string aux;
	for (int i=0; i<t; ++i){
		map<string, char> comb;
		cin>>c;
		for (int j=0; j<c; ++j){
			cin>>aux;
			string key = aux.substr(0, 2);
			comb[key] = aux[2];
			swap(key[0], key[1]);
			comb[key] = aux[2];
		}
		map<char, char> opos;
		cin>>d;
		for (int j=0; j<d; ++j){
			cin>>aux;
			opos[aux[0]] = aux[1];
			opos[aux[1]] = aux[0];
		}
		cin>>n>>aux;
		invoke(aux, comb, opos, i+1);
	}
	
	return 0;
}

