#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define N_LOW 2
#define N_HIGH 10
#define V_LOW 0
#define V_HIGH 1000
#define T_LOW 1

#define MAXN 16
#define EPS 1E-9

int main() {
    int N, i, TOT, tmp;
    double n[MAXN], first, second;

    cin >> N; assert(N_LOW <= N && N <= N_HIGH);

    TOT = 0;
    for (i=0; i<N; i++) {
        cin >> tmp; n[i] = tmp;
        assert(V_LOW <= tmp && tmp <= V_HIGH);
        TOT += tmp;
    }
    assert(T_LOW <= TOT);
    for (i=0; i<N; i++) for (int j=i+1; j<N; j++) assert(n[i] != n[j]);

    first = second = 0.0;
    for (i=0; i<N; i++) {
        n[i] /= TOT;
        if (n[i] > first) { second = first; first = n[i]; }
        else if (n[i] > second) second = n[i];
    }
    if (first > 0.45-EPS || (first > 0.40-EPS && first-second > 0.10-EPS)) cout << 1 << endl;
    else cout << 2 << endl;

    return 0;
}
