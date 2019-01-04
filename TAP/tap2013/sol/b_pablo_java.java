import java.util.*;
import java.io.*;


public class b_pablo_java {

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	int n,t=0,m1=0,m2=0,x;
	n = in.nextInt();
	for(int i=0;i<n;++i) {
		x = in.nextInt();
		t += x;
		if (x > m2) m2=x;
		if (m2 > m1) { m1 ^= m2; m2 ^= m1; m1 ^= m2; }
	}
	boolean p = (m1*100 >= t*45) || (m1*100 >= t*40 && (m1-m2)*100 >= t*10);
	System.out.println(p?'1':'2');
}

}
