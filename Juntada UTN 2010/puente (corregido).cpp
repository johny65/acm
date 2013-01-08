#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cac(vector<int> &v)
{
	sort(v.begin(), v.end());
	int suma=0;
	int t2 = v.size();
	while(t2 > 2){
		suma += v[0]+v[1];
		t2--;
		if (t2==2){
			suma+=v[t2];
			cout<<"v[t2] "<<v[t2];
			break;
		}
		suma += v[t2]+v[1];
		t2--;
		cout<<"Suma parcial: "<<suma<<'\n';
	}
	if (v.size()%2 == 0)
		suma=suma+v[1];
	cout<<"Personas: ";
	for (int i=0; i<v.size(); i++)
		cout<<" "<<v[i];
	cout<<"\nTotal: "<<suma<<'\n';
}

int main() {

	int c;
	int n;
	cin>>c;
	int t;
	
	for (int j=0; j<c; j++){
		vector<int> v;
		cin>>n;
		for (int i=0; i<n; i++){
			cin>>t;
			v.push_back(t);
		}
		cac(v);
	}
		
	return 0;
}

