#include <iostream>
#include <vector>
#include <numeric>

#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;


void calcular(vector<int> &v, int m, int k)
{
	vector<int> partes;
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
		if (contadorpartes == k-1)
			break;
			
		suma+=v[i];
		if (abs(suma-optimo) < abs(suma+v[i+1]-optimo)){ //me quedo hasta donde estoy
			partes.push_back(i);
			contadorpartes++;
			suma = 0;
		}
	}
	
	//mostrar
	int j=0;
	for (int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
		if (i == partes[j]){
			cout<<"/ ";
			j++;
		}
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

