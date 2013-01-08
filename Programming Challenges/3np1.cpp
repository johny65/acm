#include <iostream>

using namespace std;

unsigned int series[1000000] = {0};
int sns;
unsigned int ns;

unsigned int serie(unsigned int n)
{
	if (n<=1000000 && series[n-1] != 0) return series[n-1];
	unsigned int p=n;
	if (p%2==0){
		p = p/2;
	}
	else {
		p = 3*p +1;
	}
	ns=serie(p);
	sns=1+ns;
	//if (p<=1000000) series[p-1] = ns; //debería estar de más, pero no anda sin eso...
	if (n<=1000000) series[n-1] = sns;
	return sns;
}

void calcularserie(int &a, int &b)
{
	for (int i=a; i<=b; i++){
		serie(i);
	}
}

void calcular(int &i, int &j, int &a, int &b)
{
	calcularserie(i, j);
	unsigned int max=0;
	for (int k=i; k<=j; k++){
		unsigned int c=series[k-1];
		if (c>max) max=c;
	}
	printf("%i %i %u\n", a, b, max);
	
}

int main()
{
	series[0] = 1;
	int i, j, a, b;
	while (scanf("%i %i", &a, &b) != EOF){
		if (a<b){
			i=a;
			j=b;
		}
		else {
			i=b;
			j=a;
		}
		calcular(i, j, a, b);
	}
	
	return 0;
}
