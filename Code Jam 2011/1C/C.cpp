#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void harmony(vector<int> &v, ull l, ull h, int caso)
{
	ull f = l;
	while (f <= h){
		bool listo = true;
		for (int i=0; i<v.size(); ++i){
			if (f % v[i] == 0)
				continue;
			if (v[i] % f == 0)
				continue;
			listo = false;
		}
		if (listo){
			cout<<"Case #"<<caso<<": "<<f<<'\n';
			return;
		}
		f++;
	}
	cout<<"Case #"<<caso<<": NO\n";
	
	
}

int main() {
	
	int t, n;
	ull l, h;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>n>>l>>h;
		int aux;
		vector<int> v(n);
		for (int j=0; j<n; ++j){
			cin>>aux;
			v[j] = aux;
		}
		harmony(v, l, h, i+1);
	}
	return 0;
}

