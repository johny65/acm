#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void tauto(string &s)
{
	stringstream ss;
	ss<<s;
	string p;
	char car = toupper(s[0]);
	while(getline(ss, p, ' ')){
		if (toupper(p[0]) != car){
			cout<<"N\n";
			return;
		}
	}
	cout<<"Y\n";
}

int main(){
	string s;
	getline(cin, s);
	while (s != "*"){
		tauto(s);
		getline(cin, s);
	}
	return 0;
}
