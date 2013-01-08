#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> res;

bool esnumero(char c)
{
	return (c >= 48 && c<= 57);
}

void resolver(vector<string> &v)
{
	int p = v[0].find("Total"); //v[0]: línea con los códigos de producto
	switch (p) {
		case 2: {
			string temp = "P1 Totals";
			res.push_back(temp);
			break;
		}
		case 4: {
			string temp = "P1 P2 Totals";
			res.push_back(temp);
			break;
		}
		case 6: {
			string temp = "P1 P2 P3 Totals";
			res.push_back(temp);
			break;
		}
		case 8: {
			string temp = "P1 P2 P3 P4 Totals";
			res.push_back(temp);
			break;
		}
		case 10: {
			string temp = "P1 P2 P3 P4 P5 Totals";
			res.push_back(temp);
			break;
		}
	}
	/*
	for (unsigned int i=0; i<v.size(); i++)
		cout<<v[i]<<'\n';
	*/
	for (unsigned int i=1; i<v.size()-1; i++){ //siguientes líneas: nombres
		int j=0;
		string t = v[i];
		char c = t[j];
		string nombre = "";
		while (!esnumero(c)){
			nombre += c;
			j++;
			char c = t[j];
		}
		res.push_back(nombre);
	}
}


int main()
{
	int n;
	string l;
	cin>>n;
	cin.ignore();
	for (int i=0; i<n; i++){
		vector<string> caso;
		getline(cin, l);
		while (l.substr(0, 2) != "TP"){
			caso.push_back(l);
			getline(cin, l);
		}
		caso.push_back(l);
		resolver(caso);
	}
	
	//mostrar
	for (unsigned int i=0; i<res.size(); i++)
		cout<<res[i]<<'\n';
	
	return 0;
	
}
