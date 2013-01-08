#include <iostream>
#include <vector>
#include <numeric>

#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;


void calcular(vector<int> &v, int m, int k)
{
	vector< vector<int> > partes(k);
	int suma = accumulate(v.begin(), v.end(), 0);
	float optimo = suma*1.0/k;
	suma = 0;
	int contadorpartes=0;
	
	
	if(k==1){
		for(int i=0;i<v.size()-1;i++)
			cout<<v[i]<<" ";
		cout<<v[v.size()-1];
		return;
		
	}
	
	for (int i=0; i<v.size(); i++){
			
		suma+=v[i];
		partes[contadorpartes].push_back(v[i]);
		if (contadorpartes == k){
			//meter todos los que sobran
			for (int j=i+1; j<v.size(); j++)
				partes[contadorpartes].push_back(v[j]);
			break;
		}
		if (abs(suma-optimo) < abs(suma+v[i+1]-optimo)){ //me quedo hasta donde estoy
			contadorpartes++;
			suma = 0;
		}
		
	}
	
	//mostrar
	for (int i=0; i<partes.size(); i++){
		cout<<partes[i][0];
		for (int j=1; j<partes[i].size(); j++)
			cout<<" "<<partes[i][j];
		if (i != partes.size()-1)
			cout<<" / ";
	}
	
	cout<<'\n';
	
}


int main() {
	
	int n, m, k;
	cin>>n;
	for (int i=0; i<n; i++){
		
		cin>>m>>k;
		vector<int> v;
		int temp;
		for (int j=0; j<m; j++){
			cin>>temp;
			v.push_back(temp);
		}
		calcular(v, m, k);
	}
	
	return 0;
}

