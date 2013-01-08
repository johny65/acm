#include <iostream>

using namespace std;
int main()
{
	long k,res;
	int t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		cin >> k;
		res = 192 + 250 * (k - 1); 
		cout << res << endl;
	}
	
	return 0;
}
