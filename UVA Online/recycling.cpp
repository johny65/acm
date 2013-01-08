//154 Recycling
//http://uva.onlinejudge.org/external/1/154.html
//Accepted
//C++ 0.012 2012-01-27 16:35:46

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string s;
	vector< vector<char> > ciudades;
	while (getline(cin, s) && s != "#"){
		if (s[0] != 'e'){
			int i = 0;
			char r, o, y, g, b;
			while (i < s.size()){
				char color = s[i];
				char tipo = s[i+2];
				switch (color){
					case 'r':
						r = tipo; break;
					case 'o':
						o = tipo; break;
					case 'y':
						y = tipo; break;
					case 'g':
						g = tipo; break;
					case 'b':
						b = tipo; break;
				}
				i += 4;
			}
			vector<char> c;
			c.push_back(r); c.push_back(o); c.push_back(y);
			c.push_back(g); c.push_back(b); c.push_back(ciudades.size()+1);
			ciudades.push_back(c);
		}
		else {
			vector< vector<char> > resultado = ciudades;
			vector<int> cuenta(ciudades.size());
			for (int c=0; c<ciudades.size(); ++c){
				int suma=0;
				for (int i=0; i<5; ++i){
					char tipobuscado = ciudades[c][i];
					for (int c2=0; c2<ciudades.size(); ++c2){
						if (ciudades[c2][i] != tipobuscado)
							suma++;
					}
				}
				cuenta[c] = suma;
			}
			//for (int i=0; i<cuenta.size(); ++i){
				//cout<<cuenta[i]<<" ";
			//}
			//cout<<endl;
			vector<int>::iterator it = min_element(cuenta.begin(), cuenta.end());
			int minimo = distance(cuenta.begin(), it) + 1;
			cout<<minimo<<endl;
			ciudades.clear();
		}
	}
	return 0;
}
