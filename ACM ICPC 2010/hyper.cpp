#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class par {
public:
	int inicio, fin;
	bool operator < (const par &p) const { return fin < p.fin; }
};

void backtrack(vector<par> &a, int suma, int m, unsigned long long &cont, int ant, int indice)
{
	//es solución?
	if (suma == m){
		cont++;
		return;
	}
	//candidatos
	vector<int> c;
	for (int i=indice; i<a.size(); ++i){
		if (suma == 0 && a[i].inicio == 0){
			c.push_back(i);
			continue;
		}
		
		if ((a[i].inicio <= suma && a[i].fin > suma && a[i].inicio > ant) || (a[i].inicio <= suma && a[i].fin == suma && a[i].inicio > ant))
			c.push_back(i);
	}
	for (int i=0; i<c.size(); ++i){
		cont = cont % 100000000;
		backtrack(a, a[c[i]].fin, m, cont, suma, c[i]);
	}
}


int main(){
	int n, m;
	cin>>m>>n;
	while (!(n == 0 && m == 0)){
		vector<par> v(n);
		for (int i=0; i<n; ++i){
			int s, f;
			cin>>s>>f;
			par p;
			p.inicio = s; p.fin = f;
			v[i] = p;
		}
		unsigned long long cont = 0;
		sort(v.begin(), v.end());
		backtrack(v, 0, m, cont, 0, 0);
		cout<<cont % 100000000 << endl;
		cin>>m>>n;
	}
	return 0;
}

