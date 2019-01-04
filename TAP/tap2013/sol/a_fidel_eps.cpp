#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
using namespace std;

#define N_LOW 1
#define N_HIGH 1000
#define C_LOW 1
#define C_HIGH 100000

#define MAXN 1024
#define EPS 1E-12

typedef long double tint;

struct fuzzy_tint {
    tint v;
    fuzzy_tint(tint vv=0.0) { v=vv; }
};

bool operator<(const fuzzy_tint &t1, const fuzzy_tint &t2) {
    return t1.v - t2.v < -EPS;
}

struct pt {
    tint x, y;
} n[MAXN];

map<fuzzy_tint, set<int> > m;

int main() {
    int N, i, j, x, y;
    tint pos;
    set<int> res;

    cin >> N; assert(N_LOW <= N && N <= N_HIGH);
    for (i=0; i<N; i++) {
        cin >> x >> y; n[i].x = x; n[i].y = y;
        assert(C_LOW <= x && x <= C_HIGH);
        assert(C_LOW <= y && y <= C_HIGH);
    }

    for (i=0; i<N; i++) for (j=i+1; j<N; j++) {
        assert(abs(n[i].x - n[j].x) > EPS || abs(n[i].y - n[j].y) > EPS);
        if (n[i].y == n[j].y) continue;

        pos = n[i].x - n[i].y*(n[j].x - n[i].x)/(n[j].y - n[i].y);
        if (n[i].y > n[j].y) m[fuzzy_tint(pos)].insert(i);
        else m[fuzzy_tint(pos)].insert(j);
    }

    for (map<fuzzy_tint, set<int> >::iterator it=m.begin(); it!=m.end(); it++) {
		res.insert(it->second.size());
	}
    cout << res.size()+1 << endl;

    return 0;
}
