#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int G = 2;
	int C = 1;

	vector<int> v(G);
	for (int i = 0 ; i < v.size() ; i ++)
		v[i] = i;
	int r = 0;
	do
	{
		int c = 0;
		for (int i = 0 ; i < v.size() ; i ++)
		{
			if (i == v[i])
				c ++;
		}
		if (c >= C)
		{
			for (int i = 0 ; i < v.size() ; i ++)
			{
				cout << v[i] << ", ";
			}
			cout << endl;
			r ++;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << r;
	return 0;
}
