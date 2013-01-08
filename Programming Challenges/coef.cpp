#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
	if (n == 0 || n==1) return 1;
	return n*factorial(n-1);
	
}

void calcular(vector<int> &v, int n)
{
	int suma=1;
	for (int i=0; i<v.size(); i++){
		if (v[i]==0) continue;
		suma *= factorial(v[i]);
	}
	cout<<factorial(n) / suma<<'\n';
}


int main(int argc, char *argv[]) {
	
	int n, k;
	int temp;
	while (cin>>n>>k){
		vector<int> v;
		for (int i=0; i<k; i++){
			cin>>temp;
			v.push_back(temp);
		}
		calcular(v, n);
	}

	return 0;
}
