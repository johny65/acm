#include <iostream>
#include <string>
#include <set>

using namespace std;

bool todos_iguales(string &s)
{
	for (int i=0; i<s.length()-1; i++){
		if (s[i] != s[i+1]) return false;
	}
	return true;
}

void contar(string &l)
{
	if (todos_iguales(l)){
		cout<<l.length()-1<<'\n';
		return;
	}
	set<string> s;
	for (int i=0; i<l.length()-1; i++){
		string buscar = "";
		buscar += l[i];
		bool entrar, insertar;
		if (s.find(buscar) != s.end()){
			 entrar = true;
			 insertar=false;
		}
		else {
			if (l.substr(i+1, l.length()).find(buscar) == string::npos)
				entrar = false;
			else {
				entrar = true;
				insertar = true;
			}
		}
		

		//if (buscar.length() == l.length() - i - 2) continue;
		int i2 = i;
		while (entrar){
			if (insertar) s.insert(buscar);
			i2++;
			buscar += l[i2];
			if (s.find(buscar) != s.end()){
				entrar = true;
				insertar=false;
			}
			else {
				if (l.substr(i+1, l.length()).find(buscar) == string::npos)
					entrar = false;
				else {
					entrar = true;
					insertar = true;
				}
			}
		
		}
	}
	cout<<s.size()<<'\n';
	return;
}
		

int main()
{
	string l;
	getline(cin, l);
	while (l != "*"){
		contar(l);
		getline(cin, l);
	}
	return 0;
}
