#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N_LOW 1
#define N_HIGH 500
#define H_LOW 1
#define H_HIGH 1000000
#define C_LOW 2

#define MAXN 512

int h[MAXN][MAXN], sx[MAXN*MAXN], sy[MAXN*MAXN], d[MAXN][MAXN], N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int t) {
    int S, E, i, x, y;

    memset(d, -1, sizeof(d)); S = E = 0;
    d[1][1] = 0; sx[E] = 1; sy[E++] =1;
    while (S < E) {
        x = sx[S]; y = sy[S++];
        for (i=0; i<4; i++) {
            if (d[x+dx[i]][y+dy[i]] == -1 && h[x+dx[i]][y+dy[i]] > d[x][y]+t+1) {
                d[x+dx[i]][y+dy[i]] = d[x][y]+1;
                sx[E] = x+dx[i]; sy[E++] = y+dy[i];
            }
        }
    }
    return d[N][M] != -1;
}

int main() {
    int i, j, s, e, m;

    cin >> N >> M;
    assert(N_LOW <= N && N <= N_HIGH);
    assert(N_LOW <= M && M <= N_HIGH);
    assert(C_LOW <= N*M);
   
    for (i=1; i<=N; i++) for (j=1; j<=M; j++) {
        cin >> h[i][j];
        assert(H_LOW <= h[i][j] && h[i][j] <= H_HIGH);
    }
    for (i=0; i<=N+1; i++) h[i][0] = h[i][M+1] = 0;
    for (j=0; j<=M+1; j++) h[0][j] = h[N+1][j] = 0;

    if (check(0)) {
        s = 0; e = min(h[1][1], h[N][M]);
        while (e-s > 1) {
            m = (s+e)/2;
            if (check(m)) s = m;
            else e = m;
        }
        cout << s << endl;
    } else cout << -1 << endl;

    return 0;
}
