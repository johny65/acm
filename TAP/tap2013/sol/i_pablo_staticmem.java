import java.util.*;
import java.io.*;

public class i_pablo_staticmem {

static boolean[][] vis;
static int[] qi,qj,qd;
static boolean pos(int id, int n, int m, int[][] g) {
	for(int i=0;i<n;++i)for(int j=0;j<m;++j) vis[i][j]=false;
	int iqi=0,iqj=0,iqd=0,jqi=1,jqj=1,jqd=1;
	qi[0]=0; qj[0]=0; qd[0]=id;
	while(iqi < jqi) {
		int i=qi[iqi++], j=qj[iqj++], d=qd[iqd++];
		if (i>=0 && i<n && j>=0 && j<m && g[i][j]>d && !vis[i][j]) {
			if (i==n-1 && j==m-1) return true;
			vis[i][j]=true;
			for(int di=-1;di<=1;++di)for(int dj=-1;dj<=1;++dj) if (di*dj==0 && di+dj!=0) {
				qi[jqi++] = i+di;
				qj[jqj++] = j+dj;
				qd[jqd++] = d+1;
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
	vis = new boolean[n][m];
	qi = new int[4*n*m];
	qj = new int[4*n*m];
	qd = new int[4*n*m];
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
