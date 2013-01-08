//aceptado!!
//Factorial	 accepted 	0.31 	 2.5M
//Problem code: FCTRL
//https://www.spoj.pl/problems/FCTRL/

#include <iostream>
#include <cstdio>

using namespace std;

unsigned long int ceros(unsigned long int n)
{
	unsigned long int total, deno;
	if (n==5) return 1;
	if (n < 5) return 0;
	total = 0;
	deno=5;
	while (deno<=n){
		total+=n/deno;
		deno*=5;
	}
	return total;
}

int main()
{
	int t;
	unsigned long int n, c1;
	scanf("%d", &t);
	for (int i=0; i<t; ++i){
		scanf("%lu", &n);
		c1 = ceros(n);
		cout<<c1<<'\n';
	}
	return 0;
}
