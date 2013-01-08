#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> primos;

bool esprimo(int n)
{
	if (n == 2) return true;
	for (int i=2; i<=ceil(sqrt(n)); i++)
		if (n%i == 0) return false;
	
	return true;
}

void genprimos(int desde, int hasta)
{
	for (int i=desde+1; i<=hasta; i++)
		if (esprimo(i)) primos.insert(primos.end(), i);
	
}

bool bt(int n, int suma, stack<int> r, stack<int> &rf, int x)
{
	if (n == 0 && suma == x){
		rf = r;
		return true;
	}
	if (n == 0 && suma != x)
		return false;
	
	bool ban = false;
	vector<int>::iterator it = primos.begin();
	while(it != primos.end() && !ban){
		r.push(*it);
		ban = bt(n-1, suma + *it, r, rf, x);
		r.pop();
		it++;
	}
	return ban;
}

void magia(int n)
{
	stack<int> res, r;
	bt(4, 0, r, res, n);
	
	//en res tengo los 4 primos
	if (res.empty())
		cout<<"Impossible.\n";
	else {
		while (!res.empty()){
			cout<<res.top()<<" ";
			res.pop();
		}
		cout<<'\n';
	}

}

int main()
{
	int n;
	while (scanf("%i", &n)){
		magia(n);
	}
	return 0;
}
