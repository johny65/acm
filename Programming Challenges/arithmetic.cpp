#include <iostream>
#include <vector>

using namespace std;

vector<short> achar(int n)
{
	vector<short> v;
	int i=10, ia=1, dg, d = n/i;
	while (d != 0){
		d*=i;
		dg = n-d; dg/=ia;
		v.push_back(dg);
		i*=10; ia*=10;
		d = n/i;
	}
	dg = n/ia;
	v.push_back(dg);
	v.push_back(0);
	
	return v;
}

void llenarconceros(vector<short> &v, int l)
{
	for (int i=v.size(); i<=l; i++)
		v.push_back(0);
}

void mostrar(int n)
{
	switch (n){
		case 0:
			cout<<"No carry operation.\n";
			return;
		case 1:
			cout<<"1 carry operation.\n";
			return;
	}
	cout<<n<<" carry operations.\n";
}

int hacer(int n, int m)
{
	vector<short> v1 = achar(n), v2 = achar(m);
	if (v1.size() > v2.size())
		llenarconceros(v2, v1.size());
	else if (v1.size() < v2.size())
		llenarconceros(v1, v2.size());

	int carris=0;
	for (int i=0; i<v1.size(); i++){
		if (v1[i] + v2[i] >= 10){
			carris++;
			v1[i+1]++;
		}
	}
	
	return carris;
}

int main()
{
	int n, m;
	scanf("%i %i\n", &n, &m);
	while (n != 0 || m != 0){
		mostrar(hacer(n, m));
		scanf("%i %i\n", &n, &m);
	}
	return 0;
}

