#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

bool espalindromo(string n)
{
	int i=0, j=n.length()-1;
	while (i<=j){
		if (n[i] != n[j]) return false;
		i++;
		j--;
	}
	return true;
}

string mas1(string n)
{
	for (int i=0; i<n.length(); ++i)
		n[i]-='0';
		
	int carry = 1;
	int i=n.length()-1;
	while (carry != 0){
		n[i]+=carry;
		if (n[i] == 10){
			n[i] = 0;
			carry = 1;
		}
		else carry = 0;
		i--;
		if(i == -1 && carry == 1){
			n.insert(n.begin(), 1);
			carry=0;
		}
	}
	
	for (int i=0; i<n.length(); ++i)
		n[i]+='0';
	
	cout<<n<<'\n';
	return n;
}

void siguiente(string n)
{
	n = mas1(n);
	while (!espalindromo(n)){
		n = mas1(n);
	}
	cout<<n<<'\n';
}

int main()
{
	
	int t;
	string n;
	scanf("%d\n", &t);
	for (int i=0; i<t; ++i){
		getline(cin, n);
		siguiente(n);
	}
	return 0;
	
	/*
	while (true){
		string n;
		getline(cin, n);
		n = mas1(n);
		cout<<n<<'\n';
	}
	*/
}
