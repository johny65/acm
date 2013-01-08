//Conversiones entre bases numéricas

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

string tohex(int n)
{
	stringstream ss;
	ss<<hex<<n; //también para oct
	string s = ss.str();
	for (int i=0; i<s.length(); ++i)
		s[i] = toupper(s[i]);
	return s;
}

string tobin(int n)
{
	stringstream ss;
	int temp;
	while (n != 0){
		temp = n%2;
		ss<<temp;
		n/=2;
	}
	string s = ss.str();
	reverse(s.begin(), s.end());
	return s;
}

int todec(string s, int b)
{
	return strtol(s.c_str(), NULL, b);
}

int main(){
	int n;
	cout<<"Ingrese un entero: ";
	cin>>n;
	string h = tohex(n);
	cout<<"hex: "<<h<<'\n';
	int n2 = todec(h, 16);
	cout<<"de nuevo: "<<n2<<'\n';
	cout<<"binario: "<<tobin(n2)<<'\n';
	cout<<"de nuevo otra vez: "<<todec(tobin(n2), 2)<<'\n';
	return 0;
}
