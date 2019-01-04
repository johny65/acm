#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#define N_LOW 2
#define N_HIGH 1000

#define MAXN 1024
#define MOD 1000000007

int dp[MAXN][MAXN];

int _dp(int piedras, int pilas) {
    if (dp[piedras][pilas] == -1) {
        dp[piedras][pilas] = _dp(piedras, pilas-1);
        if (piedras >= pilas) dp[piedras][pilas] = (dp[piedras][pilas]+_dp(piedras-pilas, pilas))%MOD;
    }
    return dp[piedras][pilas];
}

int main() {
    int N, i, RES;

    cin >> N; assert(N_LOW <= N && N <= N_HIGH);
    
    RES = 0;
    memset(dp, -1, sizeof(dp)); dp[0][0] = 1;
    for (i=1; i<MAXN; i++) dp[i][0] = 0;
    for (i=1-N%2; i<=N; i+=2) RES = (RES+_dp(N-i, i))%MOD;
    cout << RES << endl;

    return 0;
}
