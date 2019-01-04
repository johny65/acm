#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdio>
using namespace std;

#define N_LOW 1
#define N_HIGH 500
#define P_LOW 1
#define P_HIGH N
#define C_LOW 1
#define C_HIGH 100000

#define SQ(x) ( (x)*(x) )

#define MAXN 1024
#define EPS 1E-9

typedef double tint;

const tint PI = 2.0*acos(0.0);

tint d[MAXN][MAXN];

struct pt {
    tint x, y;
    pt(tint xx=0.0, tint yy=0.0) {
        x=xx; y=yy;
    }
} n[MAXN], midpt[MAXN][MAXN], perpt[MAXN][MAXN];

pt operator-(const pt &p1, const pt &p2) {
    return pt(p1.x-p2.x, p1.y-p2.y);
}

pt operator+(const pt &p1, const pt &p2) {
    return pt(p1.x+p2.x, p1.y+p2.y);
}

pt operator*(const pt &p, const tint &c) {
    return pt(p.x*c, p.y*c);
}

pt operator/(const pt &p, const tint &c) {
    return pt(p.x/c, p.y/c);
}

tint operator*(const pt &p1, const pt &p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

tint norm(const pt &p) {
    return sqrt(p*p);
}

tint dist(const pt &p1, const pt &p2) {
    return norm(p1-p2);
}

struct event {
    int t;
    tint a;
} e[4*MAXN];

bool operator<(const event &e1, const event &e2) {
    if (e1.a != e2.a) return e1.a < e2.a;
    else return e1.t > e2.t;
}

tint normal(tint angle) {
    if (angle < 0.0) return angle+2.0*PI;
    else if (angle > 2.0*PI) return angle-2.0*PI;
    else return angle;
}

bool check(tint r, int N, int P) {
    if (P == 1) return true;

    int i, j, E, cur;

    for (i=0; i<N; i++) {
        E = 0;
        for (j=0; j<N; j++) {
            if (i == j || d[i][j] > 2.0*r) continue;

            pt per = perpt[i][j]*sqrt(SQ(r) - SQ(d[i][j]/2.0));
            pt c1 = midpt[i][j] + per;
            pt c2 = midpt[i][j] - per;

            tint a = normal(atan2((c1-n[i]).y, (c1-n[i]).x));
            tint b = normal(atan2((c2-n[i]).y, (c2-n[i]).x));

            e[E].a = a;
            if (dist(n[i] + pt(cos(a+EPS), sin(a+EPS))*r, n[j]) < r) e[E++].t = 1;
            else e[E++].t = -1;

            e[E].a = b;
            e[E++].t = -e[E-1].t;
        }
        sort(e, e+E);

        cur = 0; pt tmp = pt(n[i].x+r, n[i].y);
        for (j=0; j<N; j++) if (dist(tmp, n[j]) < r+EPS) cur++;
        for (j=0; j<E; j++) {
            cur += e[j].t;
            if (cur == P) return true;
        }
    }
    return false;
}

int main() {
    int N, P, i, j, x, y;
    tint s, e, m;

    cin >> N >> P;
    assert(N_LOW <= N && N <= N_HIGH);
    assert(P_LOW <= P && P <= P_HIGH);

    for (i=0; i<N; i++) {
        cin >> x >> y;
        assert(C_LOW <= x && x <= C_HIGH);
        assert(C_LOW <= y && y <= C_HIGH);
        n[i].x = x; n[i].y = y;
    }

    for (i=0; i<N; i++) {
        d[i][i] = 0.0;
        for (j=i+1; j<N; j++) {
            d[i][j] = d[j][i] = dist(n[i], n[j]);
            assert(d[i][j] > EPS);

            midpt[i][j] = midpt[j][i] = (n[i] + n[j])/2.0;
            perpt[i][j] = perpt[j][i] =  pt(-(n[j]-n[i]).y, (n[j]-n[i]).x)/d[i][j];
        }
    }

    s = 0.0; e = 100000.0;
    while (e-s > EPS) {
        m = (s+e)/2.0;
        if (check(m, N, P)) e = m;
        else s = m;
    }
    printf("%.4lf\n", (s+e)/2.0);

    return 0;
}
