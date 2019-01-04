import java.util.*;
import java.io.*;

public class c_pablo {

static class list extends ArrayList<Integer> {}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n = in.nextInt();
	int m = in.nextInt();
	list[] a = new list[n];
	for(int i=0;i<n;++i) a[i] = new list();
	while(m-->0) {
		int f = in.nextInt();
		int t = in.nextInt();
		a[f-1].add(t-1);
	}
	long[] cc = new long[n], mc = new long[n];
	cc[n-1]=mc[n-1]=1;
	for(int i=n-2;i>=0;--i) {
		for(int x : a[i])  {
			cc[i] += cc[x];
			mc[i] = Math.max(mc[i], mc[x]);
		}
		mc[i] += cc[i];
	}
	System.out.println(mc[0]);
}

}
