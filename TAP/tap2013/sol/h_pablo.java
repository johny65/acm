import java.util.*;
import java.io.*;

public class h_pablo {

static int maxn = 1000000;
static int sqrtmaxn = 1000;
static int maxk = 12;

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int[] d = new int[maxn+1];
	for(int i=2;i<=sqrtmaxn;++i) if (d[i]==0)
		for(int j=i*i;j<=maxn;j+=i) d[j] = i;
	
	int[][] ak = new int[maxk+1][maxn+1];
	
	int[] k = new int[maxn+1];
	for(int i=2;i<=maxn;++i) {
		if (d[i]==0) k[i]=1;
		else {
			int s=0,j=i;
			while(j>1) {
				s += d[j];
				int nd = d[j];
				if (nd == 0) { s += j; break; }
				while(j%nd==0) j=j/nd;
			}
			k[i] = k[s]+1;
		}
		ak[k[i]][i]=1;

	}
	
	for(int j=1;j<=maxk;++j)for(int i=2;i<=maxn;++i) ak[j][i] += ak[j][i-1];
	
	int p = in.nextInt();
	while(p-->0) {
		int a = in.nextInt();
		int b = in.nextInt();
		int kk = in.nextInt();
		if (kk > maxk) System.out.println(0);
		else System.out.println(ak[kk][b] - ak[kk][a-1]);
	}
}

}
