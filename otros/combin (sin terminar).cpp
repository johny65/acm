#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct letra {
	char c;
	vector<char> p;
	bool operator < (const letra &l){
		return c < l.c;
	}
};

void hacer_todo(vector<string> M, vector<string> m)
{
	vector<letra> listo;
	set<char> todas;
	//llenar todas:
	for (char i = 'A'; i<='T'; i++)
		todas.insert(todas.begin(), i);
	
	/*//mostrar conjunto
	set<char>::iterator p = todas.begin();
	while (p != todas.end()){
		cout<<*p<<'\n';
		p++;
	}
	*/
	
	int MN = M.size();
	for (int i=0; i<MN; i++){
		for (int j=0; j<4; j++){
			char c = M[i][j];
			if (c == '-') break; //esta letra ya está
			set<char> posibles;
			posibles.insert(posibles.begin(), m[i][0]);
			posibles.insert(posibles.begin(), m[i][1]);
			posibles.insert(posibles.begin(), m[i][2]);
			posibles.insert(posibles.begin(), m[i][3]);
			//busco en qué otro grupo aparece la letra mayúscula
			for (int k=0; k<MN; k++){
				if (k != i){
					set<char> posibles2, aux;
					if (M[k].find(c) != string::npos){ //la letra está en otro grupo de mayúsculas
						posibles2.insert(posibles2.begin(), m[k][0]);
						posibles2.insert(posibles2.begin(), m[k][1]);
						posibles2.insert(posibles2.begin(), m[k][2]);
						posibles2.insert(posibles2.begin(), m[k][3]);
					}
					set_intersection(posibles.begin(), posibles.end(), posibles2.begin(), posibles2.end(), inserter(aux, aux.begin()));
					posibles = aux;
				}
			}
			
			//ahora en "posibles" tengo la letra asociada, o puedo tener más
			letra temp;
			temp.c = c;
			set<char>::iterator m = posibles.begin();
			while (m != posibles.end()){
				temp.p.push_back(*m);
				p++;
			}
			listo.push_back(temp);
			m = todas.find(c);
			todas.erase(m); //saco la letra de la bolsa donde están todas
			
			//borrar la letra mayúscula para no volver a revisarla:
			for (int k=0; k<MN; k++){
				int pos = M[k].find(c);
				if (pos != string::npos)
					M[k][pos] = '-';
			}
			
		}
	}
	
	//hasta acá tengo en el vector "listo" cada letra con sus posibles asociaciones
	
	//poner las letras que no aparecieron con un ?:
	set<char>::iterator m = todas.begin();
	while (m != todas.end()){
		letra temp;
		temp.c = *m;
		temp.p.push_back('?');
		listo.push_back(temp);
		m++;
	}
	
	
	
			
			
	
	//hacer a lo último:
	//ordenar el vector listo, y mostrar las letras con sus asociaciones
}



int main()
{
	ifstream entrada("combin.in");
	int n;
	entrada>>n;
	while (n!=0){
		vector<string> may(n), min(n);
		for (int i = 0; i<n; i++) //leer letras mayúsculas
			entrada>>may[i];
		for (int i = 0; i<n; i++) //leer letras minúsculas
			entrada>>min[i];
		hacer_todo(may, min);
		entrada>>n;
	}
	return 0;
}
