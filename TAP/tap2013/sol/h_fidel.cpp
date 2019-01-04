#include <iostream>
#include <cassert>
using namespace std;

#define P_LOW 1
#define P_HIGH 100000
#define A_LOW 2
#define A_HIGH B
#define B_LOW A
#define B_HIGH 1000000
#define K_LOW 1
#define K_HIGH 1000000

#define MAXN 1048576
#define MAXK 16

int p[MAXN], k[MAXN], cant[MAXK][MAXN];

int main() {
    int P, A, B, K, i, j, sum, last;

    for (i=2; i<MAXN; i++) if (!p[i]) for (j=2*i; j<MAXN; j+=i) p[j] = i;

    for (i=2; i<MAXN; i++) {
        j = i; sum = last = 0;
        while (p[j]) {
            if (p[j] != last) sum += p[j];
            last = p[j];
            j /= p[j];
        }
        if (j != last) sum += j;
        if (sum == i) k[i] = 1;
        else k[i] = k[sum]+1;
        cant[k[i]][i]++;
    }

    for (i=1; i<MAXK; i++) for (j=3; j<MAXN; j++) cant[i][j] += cant[i][j-1];

    cin >> P;
    assert(P_LOW <= P && P <= P_HIGH);
    for (i=0; i<P; i++) {
        cin >> A >> B >> K;
        assert(A_LOW <= A && A <= A_HIGH);
        assert(B_LOW <= B && B <= B_HIGH);
        assert(K_LOW <= K && K <= K_HIGH);

        if (K < MAXK) cout << cant[K][B] - cant[K][A-1] << endl;
        else cout << 0 << endl;
    }

    return 0;
}
