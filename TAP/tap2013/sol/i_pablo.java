import java.util.*;
import java.io.*;

public class i_pablo {
	
static boolean pos(int id, int n, int m, int[][] g) {
	boolean[][] vis = new boolean[n][m];
	Queue<Integer> qi = new LinkedList<Integer>(), qj = new LinkedList<Integer>(), qd = new LinkedList<Integer>();
	qi.add(0); qj.add(0); qd.add(id);
	while(!qi.isEmpty()) {
		int i=qi.poll(), j=qj.poll(), d=qd.poll();
		if (i>=0 && i<n && j>=0 && j<m && g[i][j]>d && !vis[i][j]) {
			if (i==n-1 && j==m-1) return true;
			vis[i][j]=true;
			for(int di=-1;di<=1;++di)for(int dj=-1;dj<=1;++dj) if (di*dj==0 && di+dj!=0) {
				qi.add(i+di); qj.add(j+dj); qd.add(d+1);
			}
		}
	}
	return false;
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n = in.nextInt();
	int m = in.nextInt();
	int[][] g = new int[n][m];
	for(int i=0;i<n;++i)for(int j=0;j<m;++j) g[i][j] = in.nextInt();
	if (pos(0,n,m,g)) {
		int mn=0,mx=1000001;
		while(mx-mn > 1) {
			int md = (mx+mn)/2;
			if (pos(md,n,m,g)) mn=md; else mx=md;
		}
		System.out.println(mn);
	} else System.out.println(-1);
}

}
