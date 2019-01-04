#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define MAXN (1<<20)

using namespace std;

int next[MAXN];
int K[MAXN];
int res[MAXN][16];

int main()
{
    forn(i,MAXN)
        next[i] = 0;
    for(int i=2;i<MAXN;i++)
    if(next[i] == 0)
    {
        for(int j=2*i;j<MAXN;j+=i)
            next[j] += i;
    }
    memset(res,0,sizeof(res));
    forn(i,MAXN)
    if(next[i]==0)
    {
        res[i][1] = 1;
        K[i] = 1;
    }
    else
    {
        res[i][K[next[i]]+1] = 1;
        K[i] = K[next[i]]+1;
    }
    forn(i,16)
    for(int j=1;j<MAXN;j++)
        res[j][i] += res[j-1][i];
    int p, a, b, k;
    cin >> p;
    forn(i,p)
    {
        cin >> a >> b >> k;
        if (k < 16) cout << res[b][k]-res[a-1][k] << endl;
        else cout << 0 << endl;
    }
}
