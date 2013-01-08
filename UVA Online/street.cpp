//138 Street Numbers
//http://uva.onlinejudge.org/external/1/138.html
//Accepted
//C++ 0.520 2011-09-21 15:16:42

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int c = 0;
	unsigned long long i = 6, sumant = 13, jant = 7;
	while (c != 10){
		unsigned long long sum1 = (i-1)*i/2;
		//unsigned long long sum2 = i+1, j = i+2; //forma lenta
		unsigned long long sum2 = sumant-i, j = jant+1; //forma rápida
		while (sum2 < sum1){
			sum2 += j;
			++j;
		}
		sumant = sum2, jant = j-1;
		if (sum1 == sum2){
			cout<<setw(10)<<i<<setw(10)<<j-1<<'\n';
			++c;
		}
		++i;
	}
	return 0;
}
