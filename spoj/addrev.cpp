//aceptado!!
//Adding Reversed Numbers	 accepted 	0.43 	 2.6M
//Problem code: ADDREV
//https://www.spoj.pl/problems/ADDREV/

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int n1, n2;
	string s1, s2;
	scanf("%d", &n);
	for (int i=0; i<n; ++i){
		scanf("%d %d", &n1, &n2);
		stringstream ss1, ss2;
		ss1<<n1;
		ss2<<n2;
		s1 = ss1.str();
		s2 = ss2.str();
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		stringstream t1, t2;
		t1<<s1; t1>>n1;
		t2<<s2; t2>>n2;
		n1 = n1+n2;
		stringstream res;
		res<<n1;
		s1 = res.str();
		reverse(s1.begin(), s1.end());
		stringstream res2;
		res2<<s1;
		res2>>n1;
		cout<<n1<<'\n';
	}
	
	return 0;
}
