#include <iostream>

#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	int t, n;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>n;
		cout<<fixed<<(int)pow(2, n) - 2<<endl;
	}
	return 0;
}

