import java.util.*;
import java.io.*;


public class a_pablo_fp {

public static double fy(long x1, long y1, long x2, long y2) {
	return ((double)(x1*(y2-y1)-y1*(x2-x1)))/((double)(y2-y1));
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n;
	n = in.nextInt();
	long[] x,y;
	x = new long[n];
	y = new long[n];
	for(int i=0;i<n;++i) { x[i] = in.nextLong(); y[i] = in.nextLong(); }
	
	Map< Double, Set<Integer> > cs = new TreeMap< Double, Set<Integer> >();
	for(int i=0;i<n;++i)for(int j=0;j<n;++j) {
		if (y[i] > y[j]) {
			double xx = fy(x[i],y[i],x[j],y[j]);
			if (!cs.containsKey(xx)) cs.put(xx, new TreeSet<Integer>());
			cs.get(xx).add(i);
		}
	}
	Set<Integer> s = new TreeSet<Integer>();
	for(Map.Entry<Double, Set<Integer> > i : cs.entrySet()) {
//		System.err.println(" " + i.getKey() + " " + i.getValue());
		s.add(i.getValue().size());
	}
	System.out.println(s.size()+1);
}

}
