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

typedef long long tint;

tint gcd(tint a, tint b)
{
    return (a==0)?b:gcd(b%a,a);
}

struct racional{
    tint num, den;
    void normalizar()
    {
        if(den<0)
        {
            num *= -1;
            den *= -1;
        }
        tint t = gcd(abs(num),abs(den));
        num /= t;
        den /= t;
        return;
    }
    racional operator+(const racional &r) const
    {
        racional ret;
        ret.num = num*r.den+r.num*den;
        ret.den = den*r.den;
        ret.normalizar();
        return ret;
    }
    racional operator-(const racional &r) const
    {
        racional ret;
        ret.num = num*r.den-r.num*den;
        ret.den = den*r.den;
        ret.normalizar();
        return ret;
    }
    racional operator*(const racional &r) const
    {
        racional ret;
        ret.num = num*r.num;
        ret.den = den*r.den;
        ret.normalizar();
        return ret;
    }
    racional operator/(const racional &r) const
    {
        racional ret;
        ret.num = num*r.den;
        ret.den = den*r.num;
        ret.normalizar();
        return ret;
    }
    bool operator==(const racional &r) const
    {
        return num * r.den == den * r.num;
    }
    bool operator<(const racional &r) const
    {
        return num*r.den < r.num*den;
        /// No va a dar nunca overflow porque si bien los num son del orden de 10^10
        /// los den son del orden de 10^5
    }
};

struct pto{
    racional x, y;
};

racional alEjeX(pto p1, pto p2)
{
    /*
    (x,0),(p1.x,p1.y),(p2.x,p2.y) son colineales
    p2.y/p1.y = (p2.x-x)/(p1.x-x)
    p2.y*p1.x - p2.y*x = p2.x*p1.y - p1.y*x
    p2.y*p1.x - p2.x*p1.y = (p2.y-p1.y)*x
    x = (p2.y*p1.x-p2.x*p1.y)/(p2.y-p1.y)
    */
    return (p2.y*p1.x-p2.x*p1.y)/(p2.y-p1.y);
}

vector<pto> palmeras;

map<racional,int> puntosEspeciales;
vector<set<int> > noTeVeo;
set<int> res;

int main()
{
    int n;
    cin >> n;
    palmeras.resize(n);
    forn(i,n)
    {
        cin >> palmeras[i].x.num >> palmeras[i].y.num;
        palmeras[i].x.den = 1;
        palmeras[i].y.den = 1;
    }
    puntosEspeciales.clear();
    int t = 0;
    forn(i,n)
    forn(j,i)
    {
        if(!(palmeras[i].y==palmeras[j].y))
        {
            racional r = alEjeX(palmeras[i],palmeras[j]);
            if(puntosEspeciales.find(r)==puntosEspeciales.end())
            {
                puntosEspeciales[r] = t;
                t++;
            }
        }
    }
    noTeVeo.resize(t);
    forn(i,n)
    forn(j,i)
    {
        pto p1 = palmeras[i], p2 = palmeras[j];
        int a = j;
        if(p1.y==p2.y)
            continue;
        if(p2.y < p1.y)
        {
            swap(p1,p2);
            a = i;
        }
        racional r = alEjeX(p1,p2);
        int f = puntosEspeciales[r];
        noTeVeo[f].insert(a);
    }
    res.clear();
    forn(i,t)
        res.insert(noTeVeo[i].size());
    cout << res.size()+1 << endl;
}
