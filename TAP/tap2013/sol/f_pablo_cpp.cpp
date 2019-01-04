#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
#define forall(i,c) for(typeof(c.begin()) i=c.begin();i!=c.end();++i)

double twopi = 2.0*M_PI;

struct pt {
	double x,y;
	pt () {}
	pt (double ox, double oy) { x=ox; y=oy; } 
	double norm() { return sqrt(x*x+y*y); }
	double ang() {
		double r = atan2(y,x);
		return r<0?r+twopi:r;
	} 
};

double alpha(pt p, double r) {
	return acos(p.norm()/(2.0*r));
}

double beta(pt p, double r) {
	return p.ang();
}

void addInterval(map<double,int>& h, double f, double t) {
	h[f]++; h[t]--;
}

void addCircInterval(map<double,int>& h, double f, double t) {
	if (f < 0) {
		addInterval(h,twopi+f,twopi);
		addInterval(h,0,t);
	} else if (t >= twopi) {
		addInterval(h,f,twopi);
		addInterval(h,0,t-twopi);
	} else {
		addInterval(h,f,t);
	}
}

bool pospt(int n, pt* p, double r, int m) {
	map<double,int> h;
	for(int i=0;i<n;++i) if (p[i].norm()/2.0 <= r) {
		double a = alpha(p[i], r), b = beta(p[i], r);
		addCircInterval(h,b-a,b+a);
	}
	int t=0;
	forall(e,h) {
		t += e->second;
		if (t >= m) return true;
	}
	return false;
}

bool pos(int n, int* x, int* y, double r, int m) {
	pt p[n-1];
	for(int i=0;i<n;++i) {
		int k=0;
		for(int j=0;j<n;++j) if (i!=j) p[k++] = pt(x[j]-x[i],y[j]-y[i]);
		if (pospt(n-1, p, r, m-1)) return true;
	}
	return false;
}

int main() {
	int n,m;
	cin >> n >> m;
	int x[n],y[n];
	for(int i=0;i<n;++i) cin >> x[i] >> y[i];
	double mn = 0.4, mx = 400000.0;
	if (m<=1) mn=mx=0.0; else {
		for(int s=0;s<50;++s) {
			double md = (mx+mn)/2.0;
			if (pos(n,x,y,md,m)) mx=md; else mn=md;
		}
	}
	printf("%.4f\n",mn);
	char chs1[30],chs2[30];
	sprintf(chs1, "%.6f",mn);
	sprintf(chs2, "%.6f",mx);
	string s1(chs1),s2(chs2);
	assert(s1 == s2 && s1.substr(s1.size()-2) != "50" && s1.substr(s1.size()-2) != "49" && s1.substr(s1.size()-2) != "51");
}
