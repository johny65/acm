#include <set>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define forn(i, n) for(int i=0;i<int(n);++i)
#define forsn(i, s, n) for(int i=s;i<int(n);++i)
#define forall(i, c) for(typeof(c.begin()) i = c.begin(); i!=c.end(); ++i)
typedef long double tdbl;
typedef long long int tint;
#define sqr(a) ((a)*(a))
#define MAXN 1001
#define EPS (1e-7)

int n;
tint x[MAXN], y[MAXN];
struct Ctr{
	tdbl x, y;
	int c;
	tdbl a;
	bool operator<(const Ctr & o)const{
		return a < o.a;
	}
};
Ctr make(tdbl x, tdbl y, int c){
	Ctr r; r.x = x; r.y = y; r.c=c;
	r.a = atan2(y,x);
	return r;
}
int count_points(tdbl xc, tdbl yc, tdbl radius){
	int c=0;
	forn(i, n)c+=(sqr(x[i]-xc)+sqr(y[i]-yc)<sqr(radius)+EPS);
	return c;
}
int count(tdbl radius, int m){
        //cout << "R: " << radius << endl;
	int r=1;
	forn(i, n){
                //cout << "I: " << i << endl;
		vector<Ctr> cts;
		//cts.reserve(n-1);
		forn(j, n)if(i!=j){
			if(sqr(x[i]-x[j])+sqr(y[i]-y[j])<sqr(2.0*radius)){
				tdbl mx = (x[j]-x[i])/2.0, my = (y[j]-y[i])/2.0;
				tdbl md = hypot(mx, my);
				tdbl dx = my/md, dy=-mx/md;
				tdbl dc = sqrt(sqr(radius)-sqr(md));
				cts.push_back(make(mx+dx*dc, my+dy*dc, 1));
				cts.push_back(make(mx-dx*dc, my-dy*dc,-1));
                                //cout << "  " << j << "   (" << mx << "," << my << ")" << endl;
			}
		}
		if(cts.size()==0)continue;
                //for(int j=0;j<cts.size();j++)cout << "(" << cts[j].x << "," << cts[j].y << "," << cts[j].c << ") "; cout << endl;
		sort(cts.begin(), cts.end());
                //for(int j=0;j<cts.size();j++)cout << "(" << cts[j].x << "," << cts[j].y << "," << cts[j].c << ") "; cout << endl;
		int ini=0;
		while(cts[ini].c==-1)ini++;
		int c=count_points(x[i]+cts[ini].x, y[i]+cts[ini].y, radius);
		forsn(j, 1, cts.size()+1){
                //        cout << i << " " << ini << " " << j << " " << c << endl;
			if(r < c) r = c;
			//if (r >= m) return r;
			c += cts[(j+ini)%cts.size()].c;
		}
                //cout << "  c: " << c << endl;
                //break;
                
	}
        //cout << " r: " << r << endl;
        //cout << endl;
	return r;
}
int main(){
	int m=0;
	cin >> n >> m;
	forn(i, n)cin >> x[i] >> y[i];


        //count(65.01);
        //count(50000);
        //return 0;


	tdbl a = 0.0;
	tdbl b = 100000.0;
	while(b-a > 1e-8){
		tdbl r = (a+b)/2.0;
		if(count(r,m) < m){
			a = r;
		}else{
			b = r;
		}	
	}
	printf("%.4f\n", double(b));
	return 0;
}
