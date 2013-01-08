#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

void calcular(vector< vector<int> > &v)
{
	for (int i=0; i<v.size(); i+=2){
        int suma=0;
        sort(v[i].begin(), v[i].end());
        sort(v[i+1].begin(), v[i+1].end());
        int k=v[i].size()-1;
		for(int j=0; j<v[i].size(); j++){
			suma+=v[i][j]*v[i+1][k];
			k--;
		}
		cout<<suma<<'\n';
	}
}

int main()
{
	vector< vector<int> > entrada;
	int n;
	cin>>n;
	while (n != 0){
		vector<int> se, cal;
		for (int i=0; i<n; i++){
		    int temp;
			cin>>temp;
			se.push_back(temp);
		}
		for (int i=0; i<n; i++){
		    int temp;
			cin>>temp;
			cal.push_back(temp);
		}
		entrada.push_back(se);
		entrada.push_back(cal);
		cin>>n;
	}
	calcular(entrada);
	return 0;
}
