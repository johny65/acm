//Accepted!
//https://www.spoj.pl/problems/TOANDFRO/
//2012-01-13 20:34:35
//0.01 	2.8M

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	int n;
	string s, aux;
	while (cin>>n && n != 0){
		cin.ignore();
		getline(cin, s);
		vector<string> v;
		bool bien = true;
		int i=0;
		while (i < s.length()){
			aux = s.substr(i, n);
			if (!bien)
				reverse(aux.begin(), aux.end());
			v.push_back(aux);
			bien = !bien;
			i += n;
		}
		
		stringstream ss;
		for (int c=0; c<n; ++c){
			for (int f=0; f<v.size(); ++f)
				ss<<v[f][c];
		}
		cout<<ss.str()<<endl;
	}
	return 0;
}
