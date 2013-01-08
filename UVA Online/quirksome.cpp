//256 Quirksome Squares
//http://uva.onlinejudge.org/external/2/256.html
//Accepted
//C++ 0.008 2012-01-27 17:39:18

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	
	/* 
	// con este código encuentro los números de abajo, con entrada 2, 4, 6, 8
	int cantidades[] = {0, 0, 99, 0, 9999, 0, 999999, 0, 99999999};
	vector< vector<int> > cache(9);
	int n;
	while (cin>>n){
		int n2 = n/2;
		for (int i=0; i<cantidades[n]; ++i){
			float raiz = sqrt(i);
			if (int(raiz) == raiz){
				stringstream ss;
				ss<<setfill('0')<<setw(n)<<i;
				string s = ss.str();
				string as = s.substr(0, n2);
				string bs = s.substr(n2, n2);
				//cout<<"Cadenas: "<<as<<" "<<bs<<endl;
				int a, b;
				ss.str(""); ss.clear();
				ss<<as; ss>>a;
				ss.str(""); ss.clear();
				ss<<bs; ss>>b;
				//cout<<"Numeros: "<<a<<" "<<b<<endl;
				if ((a+b)*(a+b) == i)
					cout<<s<<endl;
			}
				
		}
	}
	*/
	
	vector<string> de2, de4, de6, de8;
	//de 2 cifras:
	de2.push_back("00");
	de2.push_back("01");
	de2.push_back("81");
	//de 4 cifras:
	de4.push_back("0000");
	de4.push_back("0001");
	de4.push_back("2025");
	de4.push_back("3025");
	de4.push_back("9801");
	//de 6 cifras:
	de6.push_back("000000");
	de6.push_back("000001");
	de6.push_back("088209");
	de6.push_back("494209");
	de6.push_back("998001");
	//de 8 cifras:
	de8.push_back("00000000");
	de8.push_back("00000001");
	de8.push_back("04941729");
	de8.push_back("07441984");
	de8.push_back("24502500");
	de8.push_back("25502500");
	de8.push_back("52881984");
	de8.push_back("60481729");
	de8.push_back("99980001");
	
	int n;
	vector<string> *v;
	while (cin>>n){
		switch (n){
			case 2: v = &de2; break;
			case 4: v = &de4; break;
			case 6: v = &de6; break;
			case 8: v = &de8; break;
		}
		for (int i=0; i<v->size(); ++i)
			cout<<(*v)[i]<<endl;
	}
	
	return 0;
}
