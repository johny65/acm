//resuelto!!

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
class algo {
	string cadena;
	double suma;
	algo(string c){ cadena = c; }
};
*/

void medir(string &comp)
{
	int sumabien = 0;
	
	//vector<algo> v;
	
//	string ss = "";
	
	double suma=0;
	
	for (int i=1; i<comp.length(); i++){
		if (comp[i] != '/'){
			//ss+=comp[i];
			switch (comp[i]){
				case 'W':
					suma+=1;
					break;
				case 'H':
					suma+=0.5;
					break;
				case 'Q':
					suma+=0.25;
					break;
				case 'E':
					suma+=1/8.0;
					break;
				case 'S':
					suma+=1/16.0;
					break;
				case 'T':
					suma+=1/32.0;
					break;
				case 'X':
					suma+=1/64.0;
					break;
			}
		}
		else { //cortar una measure
			if (abs(suma-1) < 10e-8){
				sumabien++;
			}
			suma=0;
		}

	} //del for
	
	cout<<sumabien<<'\n';
	return;
	
}

int main()
{
	string comp;
	getline(cin, comp);
	while (comp != "*"){
		medir(comp);
		getline(cin, comp);
	}
	
	return 0;
}
