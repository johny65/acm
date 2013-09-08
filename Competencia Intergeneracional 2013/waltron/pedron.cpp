#include <iostream>
#include <vector>
using namespace std;

vector<int> posibles(int n) {
	vector<int> r;
	for(int i=2; i<=n; i++) { 
		if( n % i == 0 )
			r.push_back( i - 1 );
	}
}


bool unos(int alt, int un, int &rep, int &tot, int hermanos)
{
	if (alt == 1) {
		tot += hermanos * 1;
		return un == 1;
	}
	
	vector<int> r;
	for(int i=2; i<=alt; i++) {
		if( alt % i == 0 )
			r.push_back( i - 1 );
	}
	
	for (int i=0; i<r.size(); ++i){
		if (un % r[i] != 0) continue;
		
		bool b = unos(alt / (1+r[i]), un/r[i], rep, tot, hermanos * r[i]);
		if (b) {
			rep += hermanos;
			tot += hermanos * alt;
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	int a=1, b=1;
	while (true) {
		cin>>a>>b;
		if (a == 0 && b == 0) break;
		if (a > 1){
			int rep = 0, tot = 0;
			unos(a, b, rep, tot, 1);
			cout<<rep<<" "<<tot<<endl;
		}
		else {
			cout<<"0 1";
		}
		
	}
	return 0;
}

