import java.util.*;
import java.io.*;

public class g_pablo {

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n;
	n = in.nextInt();
	int[] x,y;
	x = new int[n];
	y = new int[n];
	for(int i=0;i<n;++i) x[i] = in.nextInt(); 
	for(int i=0;i<n;++i) y[i] = in.nextInt();
	Arrays.sort(x);
	Arrays.sort(y);
	int r=0;
	for(int i=n-1,j=n-1;i>=0 && j>=0;--i,--j) {
		while(j>=0 && x[j] >= y[i]) j--;
		if (j>=0) r++;
	}
	System.out.println(r);
}

}
