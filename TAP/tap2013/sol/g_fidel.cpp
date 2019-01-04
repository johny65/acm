#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define N_LOW 1
#define N_HIGH 100000
#define V_LOW 1
#define V_HIGH 1000000000

#define MAXN 131072

int a[MAXN], b[MAXN];

int main() {
    int N, i, j, RES;

//    cin >> N;
    scanf("%d", &N);
    assert(N_LOW <= N && N <= N_HIGH);

    for (i=0; i<N; i++) {
//        cin >> a[i];
        scanf("%d", &a[i]);
        assert(V_LOW <= a[i] && a[i] <= V_HIGH);
    }
    sort(a, a+N); a[N] = V_HIGH+1;

    for (i=0; i<N; i++) {
//        cin >> b[i];
        scanf("%d", &b[i]);
        assert(V_LOW <= b[i] && b[i] <= V_HIGH);
    }
    sort(b, b+N);

    i = j = RES = 0;
    while (j < N) {
        if (a[i] < b[j]) {i++; RES++;}
        j++;
    }
    printf("%d\n", RES);
//    cout << RES << endl;

    return 0;
}
