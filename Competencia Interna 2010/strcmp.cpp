//<<
//>>

#include <iostream>

#include <string>
using namespace std;

void calcular(string &s1, string &s2)
{
	//rotar
	bool es;
	string r;
	if (s1 == s2){
		cout<<1<<'\n';
		return;
	}
	for (int i=1; i<s1.length(); ++i){
		r = s1.substr(i, s1.length());
		r += s1.substr(0, i);
		//cout<<r<<'\n';
		if (r == s2){
			cout<<1<<'\n';
			return;
		}
	}
	cout<<0<<'\n';
	return;
	
}

int main() {
	string s1, s2;
	int n;
	cin>>n;
	cin.ignore();
	for (int i=0; i<n; ++i){
		cin>>s1>>s2;
		calcular(s1, s2);
	}
	
	return 0;
}
