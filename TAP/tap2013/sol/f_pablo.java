import java.util.*;
import java.io.*;

public class f_pablo {

static double twopi = 2.0*Math.PI;

static class pt {
	public double x,y;
	public pt (double ox, double oy) { x=ox; y=oy; } 
	public double norm() { return Math.sqrt(x*x+y*y); }
	public double ang() {
		double r = Math.atan2(y,x);
		return r<0?r+twopi:r;
	} 
}

static double alpha(pt p, double r) {
	return Math.acos(p.norm()/(2.0*r));
}

static double beta(pt p, double r) {
	return p.ang();
}

static void addInterval(SortedMap<Double,Integer> h, double f, double t) {
	if (!h.containsKey(f)) h.put(f,1); else h.put(f,h.get(f)+1);
	if (!h.containsKey(t)) h.put(t,-1); else h.put(t,h.get(t)-1);
}

static void addCircInterval(SortedMap<Double,Integer> h, double f, double t) {
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

static boolean pospt(pt[] p, double r, int m) {
	SortedMap<Double,Integer> h = new TreeMap<Double,Integer>();
	for(int i=0;i<p.length;++i) if (p[i].norm()/2.0 <= r) {
		double a = alpha(p[i], r), b = beta(p[i], r);
		addCircInterval(h,b-a,b+a);
	}
	int t=0;
	for(Map.Entry<Double,Integer> e : h.entrySet()) {
		t += e.getValue();
		if (t >= m) return true;
	}
	return false;
}

static boolean pos(int[] x, int[] y, double r, int m) {
	pt[] p = new pt[x.length-1];
	for(int i=0;i<x.length;++i) {
		int k=0;
		for(int j=0;j<x.length;++j) if (i!=j) p[k++] = new pt(x[j]-x[i],y[j]-y[i]);
		if (pospt(p, r, m-1)) return true;
	}
	return false;
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n = in.nextInt();
	int m = in.nextInt();
	int[] x = new int[n], y = new int[n];
	for(int i=0;i<n;++i) {
		x[i] = in.nextInt(); 
		y[i] = in.nextInt();
	}
	double mn = 0.4, mx = 400000.0;
	if (m<=1) mn=0.0; else {
		for(int s=0;s<50;++s) {
			double md = (mx+mn)/2.0;
			if (pos(x,y,md,m)) mx=md; else mn=md;
		}
	}
	System.out.printf("%.4f\n",mn);
}

}
