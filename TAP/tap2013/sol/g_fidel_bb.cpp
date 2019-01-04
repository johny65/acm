#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 131072

int a[MAXN], b[MAXN];

int main() {
    int N, i, RES, s, e, m;

    cin >> N;

    for (i=0; i<N; i++) cin >> a[i];
    sort(a,a+N);

    for (i=0; i<N; i++) cin >> b[i];
    sort(b,b+N);

    s = 0; e = N+1;
    while (e-s > 1) {
        m = (s+e)/2;
        for (i=0; i<m; i++) if (a[i] >= b[N-m+i]) break;
        if (i == m) s = m;
        else e = m;
    }
    cout << s << endl;

    return 0;
}
