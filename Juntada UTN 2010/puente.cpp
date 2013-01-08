#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cac(vector<int> &v)
{
	sort(v.begin(), v.end());
	int suma=0;
	int t = v.size();
	int t2 = v.size();
	while(t2 > 2){
		suma += v[0]+v[1];
		suma += v[t2-1]+v[1];
		t2--;
		t2--;
	}
	suma=suma+v[1];
	cout<<suma<<'\n';
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

