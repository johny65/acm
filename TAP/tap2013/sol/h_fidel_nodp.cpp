#include <iostream>
using namespace std;

#define MAXN 1048576
#define MAXP 1100
#define MAXK 16

int p[MAXN], k[MAXN], cant[MAXK][MAXN];

int main() {
    int T, A, B, K, P, i, j, tmp, sum, last;

    P = 0;
    for (i=2; i<MAXP; i++) if (!p[i]) {
        p[P++] = i;
        for (j=2*i; j<MAXP; j+=i) p[j] = i;
    }

    for (i=2; i<MAXN; i++) {
        sum = 0; tmp = i;
        for (j=0; p[j]*p[j]<=tmp; j++) if (tmp%p[j] == 0) {
            sum += p[j];
            do {
                tmp /= p[j];
            } while (tmp%p[j] == 0);
        }
        if (tmp > 1) sum += tmp;
        
        if (sum == i) k[i] = 1;
        else k[i] = k[sum]+1;
        cant[k[i]][i]++;
    }

    for (i=1; i<MAXK; i++) for (j=3; j<MAXN; j++) cant[i][j] += cant[i][j-1];

    cin >> T;
    for (i=0; i<T; i++) {
        cin >> A >> B >> K;

        if (K < MAXK) cout << cant[K][B] - cant[K][A-1] << endl;
        else cout << 0 << endl;
    }

    return 0;
}
