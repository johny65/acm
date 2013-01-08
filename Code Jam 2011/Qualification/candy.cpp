#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void repartir(vector<int> &c, int caso)
{
	sort(c.begin(), c.end());
	cout<<"Case #"<<caso<<": ";
	int i = 1;
	while (i<c.size()){
		int suma1 = 0;
		for (int j=0; j<i; ++j){
			suma1 += c[j];
		}
		int suma2 = c[i];
		int suma = c[i];
		for (int k=i+1; k<c.size(); ++k){
			suma2 = suma2^c[k];
			suma += c[k];
		}
		if (suma1 == suma2){
			cout<<suma<<'\n';
			return;
		}
		i++;
	}
	cout<<"NO\n";
}

int main(){
	int t, n, c;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>n;
		vector<int> caramelos(n);
		for (int j=0; j<n; ++j){
			cin>>c;
			caramelos[j] = c;
		}
		repartir(caramelos, i+1);
	}

}

