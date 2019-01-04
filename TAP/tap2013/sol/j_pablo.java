import java.util.*;
import java.io.*;

public class j_pablo {

static int mod = 1000000007;
static int mem[][][];
static int cc(int p, int n, int k) {
	if (n==0) return 1-p;
	if (k<=0 || n<0) return 0;
	if (mem[p][n][k]==0) mem[p][n][k]=(cc(1-p,n-k,k)+cc(p,n,k-1))%mod+1;
	return mem[p][n][k]-1;
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n = in.nextInt();
	mem = new int[2][n+1][n+1];
	System.out.println(cc(1-n%2,n,n));
}

}
