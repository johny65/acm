#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

void put(set<int> &s, vector<int> &v)
{
	for (int i = 0 ; i < v.size() ; i ++)
	{
		
		for (int j = i ; j < v.size() ; j ++)
		{
			s.insert(fabs(v[j]-v[i]));
		}
	}
}

using namespace std;

int main()
{
	
	while (true)
	{
		
		int a, b;
		cin >> a >> b;
		
		if (a == 0 && b == 0)
			break;
			
		set<int> s;
		vector<int> v(b);
		
		for (int i = 0 ; i < b ; i ++)
			cin >> v[i];
			
		put(s, v);
		
		if (s.size() == a+1)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	
	return 0;
}
