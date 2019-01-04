import java.util.*;
import java.io.*;


public class e_pablo_java {

public static boolean todos(int l, String s) {
	boolean[] e; e = new boolean[1<<l];
	for(int i=0;i<(1<<l);++i) e[i]=false;
	int mask=(1<<l)-1;
	int a=0,c=0;
	for(int i=0;i<s.length();++i) {
		a = ((a<<1) | (s.charAt(i)-'0')) & mask;
		if (i>=l-1 && !e[a]) { e[a]=true; c++; }
	}
	return c==1<<l;
}

public static void main(String[] args) {
	Scanner in = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
	String s;
	s = in.next();
	int l=1;
	while(todos(l,s)) l++;
	System.out.println(l);
}

}
