#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
typedef long long int tint;

#define MOD 1000000007LL
#define MAXN 1024

tint dp[MAXN][MAXN][2]; //1 -> impar de pares, 0 -> par de pares 
int N;

tint _dp(int n, int m, int b){
	if (m>n) m=n;
	if (dp[n][m][b]!=-1) return dp[n][m][b];
	return dp[n][m][b] = (_dp(n-m,m,((m+b+1)&1)) + _dp(n,m-1,b)) % MOD;
}

int main () {
	cin >> N;
	assert(1<=N && N<=1000);
	memset(dp,-1,sizeof(dp));
	forn(i,N+1) {dp[i][0][0] = 0; dp[i][0][1] = 0;}
	dp[0][0][0] = 1;
	cout << _dp(N,N,1) << endl;
	return 0;
}
