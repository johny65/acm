#include <iostream>
#include <cmath>

#define ull unsigned long long

using namespace std;

ull dp[60][30];

ull nCr(int n, int r)
{
	if (n==r) return dp[n][r] = 1;
	if (r==0) return dp[n][r] = 1;
	if (r==1) return dp[n][r] = (unsigned long long)n;
	if (dp[n][r]) return dp[n][r];
	return dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

ull factorial(int n)
{
	if (n > 0)
		return n * factorial(n-1);
	else return 1;	
}

ull subf(int n)
{
	double res = factorial(n) / M_E;
	ull res2 = res + 0.5;
	return res2;
}

void dale(int a, int b)
{
	ull suma = 1;
	for (int i=b; i<a-1; ++i){
		suma += nCr(a, i)*subf(a-i);
	}
	cout<<suma%1051962371<<'\n';
}
	

int main(){
	int n;
	int a, b;
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a>>b;
		dale(a, b);
	}
	return 0;
}
