#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);++i)
#define forall(i,c) for(typeof(c.begin()) i=c.begin();i!=c.end();++i)
typedef long long tint;
typedef pair<tint,tint> pint;

tint gcd(tint a, tint b) { return a?gcd(b%a,a):b; }

tint tabs(tint x) { return x<0?-x:x; }

pint norm(const pint& p) {
	tint m = gcd(tabs(p.first),tabs(p.second));
	if (p.second<0) m=-m;
	return pint(p.first/m,p.second/m);
}

pint fy(tint x1, tint y1, tint x2, tint y2) {
	return norm(pint(x1*(y2-y1)-y1*(x2-x1),y2-y1));
}

int main() {
	tint n;
	cin >> n;
	tint x[n],y[n];
	forn(i,n) cin >> x[i] >> y[i];
	map< pint, set<int> > cs;
	forn(i,n)forn(j,n) {
		if (y[i] > y[j]) cs[fy(x[i],y[i],x[j],y[j])].insert(i);
	}
	set<int> s;
	forall(i,cs) s.insert(i->second.size());
	cout << s.size()+1 << endl;
	return 0;
}
