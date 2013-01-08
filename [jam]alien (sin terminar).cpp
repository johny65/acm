#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> s;

void calcular(string &ss, int l)
{
	vector< vector<char> > opciones(l);
	vector<char> op;
	int i=0;
	bool abierto=false;
	for (int j=0; j<ss.length(); j++){
		if (ss[j] == '('){
			j++;
			abierto=true;
		}
		else if (ss[j] == ')'){
			j++;
			opciones[i] = op;
			i++;
			abierto=false;
			op.clear();
		}
		else {
			if (abierto) op.insert(ss[j]);
			else {
				op.insert(ss[j]);
				opciones[i].insert(op);
				i++;
				op.clear();
			}
		}
	}
	
	//ya tengo todas las opciones
	
	
}

int main()
{
	string t;
	int l, d, n;
	scanf("%i %i %i\n", &l, &d, &n);
	for (int i=0; i<d; i++){
		getline(cin, t);
		s.insert(t);
	}
	for (int i=0; i<n; i++){
		getline(cin, t);
		calcular(t, l);
	}
	return 0;
}
