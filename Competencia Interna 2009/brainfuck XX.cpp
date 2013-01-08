#include <iostream>
#include <string>
#include <stack>

using namespace std;

void hacer(string l, string d, string nom)
{
	stack<int> pila;
	string salida="";
	
	//armo la celda
	unsigned char celda[30001] = {0};
	
	int pd=0, dir=0, pin=0;
	
	while (dir < l.length()){
		char c=l[dir];
		switch (c){
			case '>':
				pd++; dir++; break;
			case '<':
				pd--; dir++; break;
			case '+':
				if (celda[pd] == 255) celda[pd] = 0;
				else celda[pd]++;
				dir++;
				break;
			case '-':
				if (celda[pd] == 0) celda[pd] = 255;
				else celda[pd]--;
				dir++;
				break;
			case '.':
				if ((celda[pd]>=32 && celda[pd]<=126) || celda[pd] == '\n')
					salida.push_back(celda[pd]);
				else
					salida.push_back(' ');
				dir++; 
				break;
			case ',':
				celda[pd] = d[pin];
				pin++;
				dir++; 
				break;
			case '[':
				pila.push(dir);
				if (celda[pd] == 0){
					//saltar al próximo ]
					int ind=dir+1;
					while (42 != 3.14){
						if (l[ind] == ']') break;
						ind++;
					}
					dir = ind+1;
					pila.pop();
				}
				else {
					dir++;
				}
				break;
			case ']':
				if (celda[pd] != 0){
					dir = pila.top() + 1;
				}
				else {
					pila.pop();
					dir++;
				}
				break;
			default:
				dir++;
		} //del switch		
	} //del while
	
	if (salida.empty() || (salida[salida.length()-1] != '\n')){
		string nl="\n";
		salida+=nl;
	}
	
	cout<<"PROGRAM:"<<nom<<'\n';
	cout<<salida;
	
}


int main(int argc, char *argv[]) {
	int lc, ld;
	string nom, t, nl="\n";
	
	cin>>lc>>ld>>nom;
	cin.ignore();
	while (lc != 0 || ld != 0){
		string datos="", lineas="";
		for (int i=0; i<lc; i++){
			getline(cin, t);
			t+=nl;
			lineas+=t;
		}
		t="";
		for (int i=0; i<ld; i++){
			getline(cin, t);
			t+=nl;
			datos+=t;
		}
		//datos.push_back(0);
		hacer(lineas, datos, nom);
		cin>>lc>>ld>>nom; cin.ignore();
	}
	
	return 0;
}
