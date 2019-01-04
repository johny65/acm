#include <cstdio>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);++i)
#define forall(i,c) for(typeof(c.begin()) i=c.begin();i!=c.end();++i)

typedef long long tint;

int dist(int i, int j, int n) {
	if (i<j) return j-i; else return j+n-i;
}

int main() {
	int n,o,i,v,d;
	scanf("%d %d", &n, &d);
	tint a[n], b,c;
	map<int, set<int> > m;
	scanf("%lld %lld %lld", a, &b, &c);
	m[a[0]].insert(0);
	forn(i,n-1) m[a[i+1] = (a[i] * b + c) % d].insert(i+1);
    scanf("%d", &o);
	forn(_,o) {
		scanf("%d %d", &i, &v);
		--i;
		m[a[i]].erase(i);
		a[i] = v;
		set<int>& s = m[v];
		if (s.empty()) printf("%d %d\n", n, n);
		else {	
			set<int>::iterator it = s.lower_bound(i);
			set<int>::iterator it2 = it;
			if (it == s.begin()) it = s.end();
			--it;
			if (it2 == s.end()) it2 = s.begin();
			printf("%d %d\n", dist(*it,i,n), dist(i,*it2,n));
		}
		s.insert(i);
	}
	return 0;
}
