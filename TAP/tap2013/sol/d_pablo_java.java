import java.util.*;
import java.io.*;


public class d_pablo_java {

public static int dist(int i, int j, int n) {
	if (i<j) return j-i; else return j+n-i;
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n = in.nextInt();
	int d = in.nextInt();
	int[] a;
	a = new int[n];
	long b,c;
	Map<Integer, SortedSet<Integer> > m = new TreeMap<Integer, SortedSet<Integer> >();
	a[0] = in.nextInt();
	b = in.nextLong();
	c = in.nextLong();
	SortedSet<Integer> s0 = new TreeSet<Integer>();
	s0.add(0);
	m.put((int)a[0],s0);
	for(int i=0;i<n-1;++i) {
		a[i+1] = (int)((((long)a[i]) * b + c) % d);
		if (!m.containsKey(a[i+1])) m.put(a[i+1], new TreeSet<Integer>());
		m.get(a[i+1]).add(i+1);
	}
	int o = in.nextInt();
	for(int k=0;k<o;++k) {
		int i = in.nextInt()-1;
		int v = in.nextInt();
		m.get(a[i]).remove(i);
		a[i] = v;
		if (!m.containsKey(v)) m.put(v, new TreeSet<Integer>());
		SortedSet<Integer> s = m.get(v);
		if (s.isEmpty()) System.out.println("" + n + " " + n);
		else {	
			SortedSet<Integer> it = s.headSet(i);
			SortedSet<Integer> it2 = s.tailSet(i);
			if (it.isEmpty()) it = s;
			if (it2.isEmpty()) it2 = s;
			System.out.println("" + dist(it.last(),i,n) + " " + dist(i,it2.first(),n));
		}
		s.add(i);
	}
}

}
