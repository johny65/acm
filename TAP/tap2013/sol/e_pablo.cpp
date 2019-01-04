#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);++i)
#define forall(i,c) for(typeof(c.begin()) i=c.begin();i!=c.end();++i)

bool todos(int l, const string& s) {
	bool e[1<<l];
	forn(i,(1<<l)) e[i]=false;
	int mask=(1<<l)-1;
	int a=0,c=0;
	forn(i,s.size()) {
		a = ((a<<1) | (s[i]-'0')) & mask;
		if (i>=l-1 && !e[a]) { e[a]=true; c++; }
	}
	return c==1<<l;
}

int main() {
	string s;
	cin >> s;
	int l=1;
	while(todos(l,s)) l++;
	cout << l << endl;
	return 0;
}
