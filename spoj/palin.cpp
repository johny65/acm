//accepted
//The Next Palindrome	accepted	0.80 	2.8M
//Problem code: PALIN
//https://www.spoj.pl/problems/PALIN/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

string inc(string &s)
{
	bool carry=true;
	int i = 1;
	while (carry){
		if (s[s.length()-i]	== '9'){
			s[s.length()-i] = '0';
			if (i==s.length()){
				s = "1" + s;
				carry = false;
			}
		}
		else {
			s[s.length()-i] = s[s.length()-i]+1;
			carry=false;
		}
		i++;
	}
	return s;
}

bool espalindromo(string &n)
{
	int i=0;
	int j=n.length()-1;
	while (i<=j){
		if (n[i] != n[j]) return false;
		i++;
		j--;
		if (i == n.length() || j==0)
			return true;
	}
	return true;
}

void siguiente(string &n)
{
	inc(n);
	if (n.length() % 2 == 0){
		string n2 = n.substr(0, n.length()/2);
		do {
			string n3 = n2;
			reverse(n3.begin(), n3.end());
			n3 = n2+n3;
			if (n3 >= n){
				cout<<n3<<'\n';
				return;
			}
			inc(n2);
		} while(true);
	}
	else {
		string n2 = n.substr(0, (n.length()-1)/2+1);
		do {
			string n3 = n2.substr(0, n2.length()-1);
			reverse(n3.begin(), n3.end());
			n3 = n2+n3;
			if (n3 >= n){
				cout<<n3<<'\n';
				return;
			}
			inc(n2);
		} while(true);
	}
}

int main()
{
	int t;
	string n;
	cin>>t; cin.ignore();
	for (int i=0; i<t; ++i){
		getline(cin, n);
		siguiente(n);
	}
	return 0;
}
