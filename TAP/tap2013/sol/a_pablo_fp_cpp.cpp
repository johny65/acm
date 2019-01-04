#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);++i)
#define forall(i,c) for(typeof(c.begin()) i=c.begin();i!=c.end();++i)
typedef long long tint;
typedef long double ld;

ld fy(tint x1, tint y1, tint x2, tint y2) {
	return ld(x1*(y2-y1)-y1*(x2-x1))/ld(y2-y1);
}

int main() {
	tint n;
	cin >> n;
	tint x[n],y[n];
	forn(i,n) cin >> x[i] >> y[i];
	map< ld, set<int> > cs;
	forn(i,n)forn(j,n) {
		if (y[i] > y[j]) cs[fy(x[i],y[i],x[j],y[j])].insert(i);
	}
	set<int> s;
	forall(i,cs) s.insert(i->second.size());
	cout << s.size()+1 << endl;
	return 0;
}
