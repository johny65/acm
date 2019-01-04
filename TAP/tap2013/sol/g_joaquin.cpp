#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()

using namespace std;

int main(){
    int S;
    vector<int> a, b;
    
    cin >> S;
	forn(i, S){ int tmp; cin >> tmp; a.push_back(tmp); }
	sort(all(a));
	forn(i, S){ int tmp; cin >> tmp; b.push_back(tmp); }
	sort(all(b));
    
    int ia = 0, ib = 0;
    int res = 0;
    
    while(ia < S){
		while(ib < S && b[ib] <= a[ia]) ib++;
		if(ib < S) res++;
		ia++; ib++;
	}

	cout << res << endl;
    
    return 0;    
}
