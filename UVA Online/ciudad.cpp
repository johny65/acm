//105 The Skyline Problem:
//http://uva.onlinejudge.org/external/1/105.html
//Accepted
//C++ 0.052 2011-09-21 01:39:29

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int l, r, h, maxr = 0;
	vector<int> v(20002, 0);
	while (cin>>l>>h>>r){
		int r2 = 2*r-1;
		for (int i=l*2-1; i<=r2; ++i)
			v[i] = max(v[i], h);
		maxr = max(maxr, r);
	}
	int ant, i=1, maxr2 = 2*maxr;
	while (v[i] == 0)
		++i;
	cout<<i<<" "<<v[i]; //acá arranca
	ant = v[i];
	for (i = i+1; i<=maxr2; ++i){
		if (v[i] != ant){
			if (v[i] > ant)
				cout<<" "<<(i+1)/2<<" "<<v[i];
			else
				cout<<" "<<i/2<<" "<<v[i];
			ant = v[i];
		}
	}
	cout<<'\n';
	return 0;
	
}
