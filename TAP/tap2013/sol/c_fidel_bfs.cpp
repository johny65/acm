#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 32768

struct node {
    long long res, cant;
    int in;
    vector<int> c;
} n[MAXN];

int s[MAXN];

int main() {
    int N, S, i, L, R, cur, next, a, b;

    cin >> N >> S;
    for (i=0; i<S; i++) {
        cin >> a >> b;
        n[b].c.push_back(a);
        n[a].in++;
    }

    L = R = 0;
    for (i=1; i<=N; i++) if (n[i].in == 0) s[R++] = i;
    n[N].cant = 1LL;
    while (L < R) {
        cur = s[L++];

        n[cur].res += n[cur].cant;
        for (i=0; i<(int)n[cur].c.size(); i++) {
            next = n[cur].c[i];
            n[next].cant += n[cur].cant;
            n[next].res = max(n[next].res, n[cur].res);
            n[next].in--;
            if (n[next].in == 0) s[R++] = next;
        }
    }
    cout << n[1].res << endl;

    return 0;
}
