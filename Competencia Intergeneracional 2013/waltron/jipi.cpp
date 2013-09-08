#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[]) {
	int t, n;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>n;
		vector< vector<int> > grilla(n, vector<int>(n, 0));
		for (int f=0; f<n; ++f)
			for (int c=0; c<n; ++c)
				cin>>grilla[f][c];
		
		vector<int> dir(3);
		for (int f=1; f<n; ++f){
			for (int c=0; c<n; ++c){
				dir[0] = (c>0)?	grilla[f-1][c-1] 	+ grilla[f][c] : 0;
				dir[1] = 			grilla[f-1][c] 		+ grilla[f][c];
				dir[2] = (c<n-1)? 	grilla[f-1][c+1] 	+ grilla[f][c] : 0;
				
				grilla[f][c] = *max_element( dir.begin(), dir.end());
			}
		}
		
		int max = *max_element( grilla.back().begin(), grilla.back().end());
		cout<<max<<endl;
	}
	return 0;
}

