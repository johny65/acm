#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calcular(vector< vector<int> > &v, int n)
{
	
//	for (int i=1; i<v.size(); ++i){
//		for (int j=0; j<v[i].size(); ++j){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	
	
	unsigned long int suma=0;
	for (int i=1; i<v.size(); ++i){
		suma+=2000; //me sumo yo
		//sumo a mis amigos
		suma+=1000*(v[i].size()-1);
		//sumo a los amigos de los amigos
		for (int j=1; j<=n; ++j){
			if (find(v[i].begin(), v[i].end(), j) != v[i].end()){ //si j es mi amigo, sumar sus amigos
				for (int k=1; k<v[j].size(); ++k){ //recorrer los amigos de j
					if (v[j][k] != i && find(v[i].begin(), v[i].end(), v[j][k]) == v[i].end()){
						if (v[v[j][k]][0] != -1)
							suma+=100;
						//no contarlo más como amigo de un amigo
						v[v[j][k]][0]=-1;
						//cout<<v[j][k]<<'\n';
					}
					
				}
			}
			
		}
		
		//volver a 0
		for (int m=0; m<n+1; ++m)
			v[m][0] = 0;
	}
	cout<<suma<<'\n';
}

int main() {
	int n, r;
	cin>>n>>r;
	while (!(n == 0 && r == 0)){
		vector< vector<int> > v(n+1);
		for (int j=0; j<n+1; ++j)
			v[j].push_back(0);
		int a, b;
		for (int i=0; i<r; ++i){
			cin>>a>>b;
			if (find(v[a].begin(), v[a].end(), b) == v[a].end())
				v[a].push_back(b);
			if (find(v[b].begin(), v[b].end(), a) == v[b].end())
				v[b].push_back(a);
		}
		calcular(v, n);
		cin>>n>>r;
	}
	
	return 0;
}
