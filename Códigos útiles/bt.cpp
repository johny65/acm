#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<bool> a, int k, int n)
{
	if (k == n){ //es solución?
		cout<<"{ ";
		for (int i=1; i<=k; ++i)
			if (a[i]) cout<<i<<" ";
		cout<<"}\n";
	}
	else {
		++k;
		a[k] = true;
		backtrack(a, k, n);
		a[k] = false;
		backtrack(a, k, n);
	}
}

void generate_subsets(int n)
{
	vector<bool> a(n+1);
	backtrack(a, 0, n);
}

int main(){
	generate_subsets(5);
	return 0;
}
