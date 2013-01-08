#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool espalindromo(unsigned int n)
{
	stringstream ss;
	ss<<n;
	string s = ss.str();
	int i = 0, j = s.length()-1;
	while (i <= j){
		if (s[i] != s[j]) return false;
		++i;
		--j;
	}
	return true;
}

void calcular(unsigned int p)
{
	int it = 1;
	unsigned int r;
	while (true){
		stringstream ss;
		ss<<p;
		string s = ss.str();
		reverse(s.begin(), s.end());
		ss.str("");
		ss<<s;
		ss>>r;
		p += r;
		if (espalindromo(p)){
			printf("%d %u\n", it, p);
			return;
		}
		++it;
	}
}

int main(){
	int n;
	unsigned int p;
	scanf("%d\n", &n);
	for (int i=0; i<n; ++i){
		scanf("%u", &p);
		calcular(p);
	}
	return 0;
}
