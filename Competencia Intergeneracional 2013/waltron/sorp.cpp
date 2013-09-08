#include <iostream>
using namespace std;

int l[] = { 4, 3, 3, 4, 6, 5, 4, 5, 4, 5, 4, 4, 4, 5, 7, 6, 9, 10, 9, 10, 6, 9, 9, 10, 12, 11, 10, 11, 10, 11, 7};

int main(int argc, char *argv[]) {
	int n;
	while(cin>>n)
		cout<<l[n]<<endl;
	return 0;
}

