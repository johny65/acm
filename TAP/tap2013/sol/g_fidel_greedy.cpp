#include <iostream>
#include <set>
using namespace std;

#define MAXN 131072

int a[MAXN];
multiset<int> b;

int main() {
    int N, i, RES, tmp;
    multiset<int>::iterator it;

    cin >> N;
    for (i=0; i<N; i++) cin >> a[i];
    for (i=0; i<N; i++) { cin >> tmp; b.insert(tmp); }

    RES = 0;
    for (i=0; i<N; i++) {
        it = b.upper_bound(a[i]);
        if (it != b.end()) { RES++; b.erase(it); }
    }
    cout << RES << endl;

    return 0;
}
