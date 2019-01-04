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

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	forn(i,n)
        cin >> vec[i];
    sort(all(vec));
    reverse(all(vec));
    int f = vec[0], s = vec[1], tot = 0;
    forn(i,n)
        tot += vec[i];
    if(f*100>=tot*45)
        cout << "1"<< endl;
    else if(f*100>=tot*40 && (f-s)*100 >= tot*10)
        cout << "1"<< endl;
    else
        cout << "2"<< endl;
}
