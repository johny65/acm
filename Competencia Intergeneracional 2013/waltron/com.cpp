#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int funcion(vector< vector<int> > &vecinos, vector<int> &avisados, int ultimo)
{
	int minimo = 42;
	int r;
	for (int i=ultimo+1; i<vecinos.size(); ++i){
		//if (avisados[i]) continue;
		
		avisados[i]++;
		for (int j=0; j<vecinos[i].size(); ++j)
			avisados[vecinos[i][j]]++;
		
		r = funcion(vecinos, avisados, i) + 1;
		
		avisados[i]--;
		for (int j=0; j<vecinos[i].size(); ++j)
			avisados[vecinos[i][j]]--;
		
		if (r < minimo) minimo = r;
	}
	
	bool sinavisar = false;
	for(int i=0;i<vecinos.size();i++) { 
		if (!avisados[i]) {
			sinavisar = true;
			break;
		}
	}
	
	if (!sinavisar) return 0;
	else return minimo;
}




int main(int argc, char *argv[]) {
	int n; //cantidad de amigos
	cin>>n;
	map<string, int> amigos;
	string s, s2;
	for (int i=0; i<n; ++i){
		cin>>s;
		amigos[s] = i;
	}
	vector< vector<int> > vecinos(n);
	while (cin>>s>>s2) {
		vecinos[amigos[s]].push_back(amigos[s2]);
		vecinos[amigos[s2]].push_back(amigos[s]);
	}
	
	int r = 0;
	
	vector<int> avisados(n, 0);
	for(int i=0;i<n;i++) {
		if (vecinos[i].size() == 0){
			vecinos.erase(vecinos.begin()+i);
			r++;
		}
		if (vecinos[i].size() == 1 && vecinos[vecinos[i][0]].size() == 1){
			vecinos.erase(vecinos.begin()+i);
			vecinos.erase(vecinos.begin()+vecinos[i][0]);
			r++;
		}
	}
	
	r += funcion(vecinos, avisados, -1);
	
	cout<<r<<endl;
	return 0;
}

