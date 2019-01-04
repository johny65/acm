#include <iostream>
#include <cassert>
#include <set>
#include <cstdio>
using namespace std;

#define N_LOW 3
#define N_HIGH 100000
#define O_LOW 1
#define O_HIGH 100000
#define C_LOW 1
#define C_HIGH 1000000
#define V_LOW 0
#define V_HIGH D-1

#define MAXN 131072
#define MAXV 1048576

int n[MAXN];
set<int> pos_inc[MAXV], pos_dec[MAXV];

int main() {
    int N, O, i, POS, V, D;
    long long A, B, C;

    scanf("%d %d", &N, &D);
    assert(N_LOW <= N && N <= N_HIGH);
    assert(C_LOW <= D && D <= C_HIGH);

    scanf("%lld %lld %lld", &A, &B, &C);
    assert(V_LOW <= A && A <= V_HIGH);
    assert(V_LOW <= B && B <= V_HIGH);
    assert(V_LOW <= C && C <= V_HIGH);

    
    for (i=1; i<=N; i++) {
        n[i] = A;
        pos_inc[n[i]].insert(i); pos_inc[n[i]].insert(i+N);
        pos_dec[n[i]].insert(-i); pos_dec[n[i]].insert(-i+N);
        A = (A*B+C)%D;
    }

    scanf("%d", &O);
    assert(O_LOW <= O && O <= O_HIGH);
    for (i=0; i<O; i++) {
        scanf("%d %d", &POS, &V);
        assert(1 <= POS <= N);
        assert(V_LOW <= V <= V_HIGH);

        pos_inc[n[POS]].erase(POS); pos_inc[n[POS]].erase(POS+N);
        pos_dec[n[POS]].erase(-POS); pos_dec[n[POS]].erase(-POS+N);
        pos_inc[V].insert(POS); pos_inc[V].insert(POS+N);
        pos_dec[V].insert(-POS); pos_dec[V].insert(-POS+N);
        n[POS] = V;
        printf("%d %d\n", POS+(*pos_dec[n[POS]].upper_bound(-POS)), (*pos_inc[n[POS]].upper_bound(POS))-POS);
    }

    return 0;
}
