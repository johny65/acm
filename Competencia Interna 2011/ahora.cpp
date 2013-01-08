#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class problem {
public:
	int resueltos, num;
	char letra;
	problem(int r, char l, int n) : resueltos(r), letra(l), num(n) {}
	bool operator<(const problem &p) const {
		return resueltos > p.resueltos;
	}
};

void ver(vector<string> &v, int n, int p)
{
	string res = "";
	vector<problem> ps;
	for (int c=0; c<p; ++c){
		int suma =0;
		for (int f=0; f<n; ++f){
			if (v[f][c] == '1')
				suma += 1;
		}
		problem pro(suma, 'A' + c, c);
		ps.push_back(pro);
	}
	stable_sort(ps.begin(), ps.end());

	for (int i=0; i<v.size(); ++i){ //equipos		
		string s = v[i];
		bool f2 = true;			
		for (int j=0; j<ps.size() && f2; ++j){
			if (s[ps[j].num] != '1'){
				cout<<ps[j].letra;
				f2 = false;
				break;
			}
		}
		if (f2) cout<<'*';
	}
	cout<<endl;
}

int main() {
	
	string l;
	int n, p;
	while (cin>>n>>p && n != 0 && p != 0){
		cin.ignore();
		vector<string> v(n);
		string s;
		for (int i=0; i<n; ++i){
			getline(cin, s);
			v[i] = s;
		}
		ver(v, n, p);
	}	
	return 0;
}

