#include <cstdio>

unsigned long long dp[60][30];

unsigned long long nCr(int n, int r)
{
    if (n==r) return dp[n][r] = 1;
    if (r==0) return dp[n][r] = 1;
    if (r==1) return dp[n][r] = (unsigned long long)n;
    if (dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

int main()
{
    int n, r;
    while(scanf("%d %d",&n,&r)==2)
    {
        r = (r<n-r)? r : n-r;
        printf("%llu\n",nCr(n,r));
    }
    return 0;
}
