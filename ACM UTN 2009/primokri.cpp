#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool esprimo (unsigned long long pr) {
	if (pr == 2) return true;
	
	for (unsigned long long i = 2; i <= sqrt(pr); i++) {
		if (pr % i == 0) return false;
	}
	
	return true;
}


unsigned long long primo(unsigned long long pr) {
	while(true) {
		pr++;
		if (esprimo(pr)) return pr;	
	}
	
	
	
	
}


void generate (vector<unsigned long long> &p, int size) {
	int pr = 1;
	p.resize(size);

	for (int i = 0; i < size; i++) {
		pr = primo(pr);
		p[i] = pr;
	}
}





string encrypt(string msg) {
	vector<unsigned long long> primos;
	string enc;
	int cont = 1, red = 1, ix = 0;
	
	generate(primos, msg.size());
	
	enc.resize(primos[primos.size()-1], '|');
	reverse(msg.begin(), msg.end());
	
	for (int i = 0; i < msg.size(); i++) {
		enc[primos[i]-1] = msg[i];
	}
	
	reverse(msg.begin(), msg.end());
	
	while (msg[ix] == ' ') ix++;
	
	for (int i = 0; i < enc.size(); i++) {
		if (red == 0) {
			cont++;
			red = cont;
			ix++;
			while (msg[ix] == ' ') {ix++;}
			//if (ix == msg.size() -1) ix = 0;
		}
			
		if (enc[i] == '|') {
			enc[i] = msg[ix];
			red--;
		}
		
	}
	
	return enc;
}

int main(int argc, char *argv[]) {
	int c;
	string msg;
	
	while (cin >> c) {
		cin.ignore();
	
		for (int i = 0; i < c; i++) {
			getline(cin, msg);
			cout << encrypt(msg) << endl;		
		}
		
	}
	
	return 0;
}

