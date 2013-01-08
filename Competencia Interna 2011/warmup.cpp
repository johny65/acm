#include <iostream>

using namespace std;

int main(){
	string s;
	while (getline(cin, s) && s != "---"){
		cout<<42<<endl;
	}
	return 0;
}
