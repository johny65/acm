#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int lala (int x) {
	switch(x) {
	case 1: return 192;
	case 2: return 442;
	case 3: return 692;
	case 4: return 942;
	}
}

int main(int argc, char *argv[]) {
	long long long c, t;
	
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> t;
		
		if (t <= 4) cout << lala(t) << endl;
		else if (t % 4 != 0){
			cout << t/4 << lala(t%4) << endl;
		}
		else {
			cout << (t-1)/4 << lala(4) << endl;
		}
		
		
		
	}
	
		
	return 0;
}

