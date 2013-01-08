#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;

using namespace std;


void hacer(int n, int &l, ull t, vector<ull> dis, int caso)
{
	vector<ull> d(n);
	for (int i=0; i<n; ++i){
		d[i] = dis[i%dis.size()];
	}
	
	ull horas=0;
	ull maximo = *max_element(dis.begin(), dis.end());
	bool listos=false;
	for (int i=0; i<n; ++i){
		for (ull paso=0; paso<d[i]; ++paso){
			if (listos && l != 0){
				if (l >= n-i-1 || d[i] == maximo){
					horas+=d[i]-paso;
					l--;
					break;
				}
				else horas+=2;
				//else if (d[i] == maximo) {
					
				//}
			}
			else horas+=2;
			if (horas >= t)
				listos=true;
		}
	}
	cout<<"Case #"<<caso<<": "<<horas<<'\n';
}

int main(){

	int T, l, n, c;
	ull t;
	cin>>T;
	for (int i=0; i<T; ++i){
		cin>>l>>t>>n>>c;
		ull ai;
		vector<ull> dis(c);
		for (int j=0; j<c; ++j){
			cin>>ai;
			dis[j] = ai;
		}
		hacer(n, l, t, dis, i+1);
	}
	
}
