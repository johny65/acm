#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

	string s, magicline = "lalala";
	getline(cin, s);
	bool listo=false;
	while (s != "EOF"){
		if (!listo){
			if (s != magicline)
				cout<<"Hello, world!\n";
			else
				listo=true;
		}
		getline(cin, s);
	}
	return 0;
}
