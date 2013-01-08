#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class persona {
public:
	int indice;
	int prob;
	vector<string> al;
	persona(int i){
		indice = i;
		prob=1;
	}
	bool operator<(const persona &p) const {
		if (prob < p.prob) return true;
		else if (prob > p.prob) return false;
		else { //prob==p.prob
			if (indice > p.indice) return true;
			else return false;
		}
	}
	
};

void superpoderosa(vector<persona> &personas, map<char, int> &alelos)
{
	persona &per1 = personas[0];
	//revisar por locus
	for (int k=0; k<per1.al.size(); k++){
		for (int j=1; j<personas.size(); j++){
			char al1 = personas[j].al[k][0];
			char al2 = personas[j].al[k][1];
			char alp1 = per1.al[k][0];
			char alp2 = per1.al[k][1];
			int frec=1;
			if ((al1 == alp1 || al1 == alp2) && (al2 == alp2 || al2 == alp1)){ //tienen los mismos 2 alelos
				frec = min(alelos[al1], alelos[al2]);
			}
			else if (al1 == alp1 || al1 == alp2){
				frec = alelos[al1];
			}
			else if (al2 == alp2 || al2 == alp1){
				frec = alelos[al2];
			}
			personas[j].prob*=frec;
		}
	}

	sort(personas.begin(), personas.end());
	int &pp = personas[personas.size()-1].prob;
	
	if (pp == 1){ //ninguna coincidencia
		cout<<"0:2";
		for (int i=3; i<personas.size()+1; i++)
			cout<<" "<<i;
	}
	else {
		cout<<pp<<":"<<personas[personas.size()-1].indice;
		for (int i=personas.size()-2; i>0 && personas[i].prob == pp; i--){
			cout<<" "<<personas[i].indice;
		}
	}
	cout<<'\n';
		
		
	/*
	for (int i=0; i<personas.size(); i++){
		cout<<"Persona "<<i+1<<": "<<personas[i].prob<<'\n';
	}
	
	for (map<char, int>::iterator i=alelos.begin(); i!=alelos.end(); i++){
		cout<<"Alelo "<< i->first <<": "<< i->second<<'\n';
	}
	*/
	
	alelos.clear();
		
}

int main()
{
	int a, c, l;
	int p;
	string par;
	map<char, int> alelos; //los alelos con sus probabilidades
	
	cin>>a>>c;
	while (a != 0 && c != 0){
		cin>>l;
		char alelo = 'A';
		for (int i=0; i<a; i++){
			cin>>p;
			alelos[alelo] = p;
			alelo++;
		}
		
		//crear el vector de personas
		vector<persona> personas;
		for (int i=0; i<c; i++)
			personas.push_back(persona(i+1));
			
		for (int i=0; i<l; i++){
			for (int j=0; j<c; j++){
				cin>>par;
				personas[j].al.push_back(par);
			}
		}
		superpoderosa(personas, alelos);
		cin>>a>>c;
	}
	
	return 0;
}
