import java.util.*;
import java.io.*;

public class g_pablo_set {

public static void add(Map<Integer,Integer> s, int x) {
	if (!s.containsKey(x)) s.put(x,1); else s.put(x,s.get(x)+1);
}

public static void erase(Map<Integer,Integer> s, int x) {
	if (s.get(x) == 1) s.remove(x); else s.put(x,s.get(x)-1);
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n;
	n = in.nextInt();
	SortedMap<Integer,Integer> x = new TreeMap<Integer,Integer>(),y = new TreeMap<Integer,Integer>();
	for(int i=0;i<n;++i) add(x,in.nextInt()); 
	for(int i=0;i<n;++i) add(y,in.nextInt());
	int r=0;
	for(Map.Entry<Integer,Integer> e : y.entrySet()) {
		for(int k=0;k<e.getValue();++k) {
			SortedMap<Integer,Integer> m = x.headMap(e.getKey());
			if (!m.isEmpty()) {
				r++;
				erase(x, m.lastKey());
			}
		}
		
	}
	System.out.println(r);
}

}
