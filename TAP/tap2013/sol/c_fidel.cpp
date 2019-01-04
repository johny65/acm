#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define N_LOW 3
#define N_HIGH 30000
#define S_LOW 2
#define S_HIGH 100000
#define C_LOW 1
#define C_HIGH N
#define R_LOW 1LL
#define R_HIGH 1000000000000000000LL

#define MAXN 32768

struct node {
    long long cant, res;
    vector<int> c;
} n[MAXN];

void dfs(int cur) {
    n[cur].cant = n[cur].res = 0;
    for (int i=0; i<(int)n[cur].c.size(); i++) {
        int next = n[cur].c[i];
        if (n[next].cant < 0) dfs(next);
        n[cur].cant += n[next].cant;
        assert(n[cur].cant < R_HIGH);
        n[cur].res = max(n[cur].res, n[next].res);
    }
    n[cur].res += n[cur].cant;
    assert(n[cur].res < R_HIGH);
}

int main() {
    int N, S, a, b, i;

    cin >> N >> S;
    assert(N_LOW <= N && N <= N_HIGH);
    assert(S_LOW <= S && S <= S_HIGH);

    for (i=0; i<S; i++) {
        cin >> a >> b;
        assert(C_LOW <= a && a < b && b <= C_HIGH);

        n[a].c.push_back(b);
    }
    for (i=1; i<N; i++) n[i].cant = n[i].res = -1; n[N].cant = n[N].res = 1;
    dfs(1); assert(R_LOW <= n[1].res && n[1].res <= R_HIGH);
    cout << n[1].res << endl;

    return 0;
}
