#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int minn(vector<int> &v, int n, int &gano)
{
	int mi = 53;
	for (int i = 0 ; i < v.size() ; i ++)
	{
		if (v[i] > n)
		{
			if (v[i] < mi)
				mi = v[i];
		}
	}
	
	// No encontro
	if (mi == 53)
	{
		for (int i = 0 ; i < v.size() ; i ++)
		{
			if (v[i] < mi)
				mi = v[i];
		}
	}
	else
		gano ++;
		
	// Borrar mi de v
	for (int i = 0 ; i < v.size() ; i ++)
	{
		if (mi == v[i])
			v.erase(v.begin()+i);
	}
	
	return mi;
}

int main()
{
	while (true)
	{
		
		int a, b, c, x, y;
		
		cin >> a >> b >> c >> x >> y;
		
		if (a == 0 && b == 0 && c == 0 && x == 0 && y == 0)
			break;
		
		set<int> s;	
		int mi1, ma1;
		int gano=0;
		if (x > y)
		{
			mi1 = y;
			ma1 = x;
		}
		else
		{
			mi1 = x;
			ma1 = y;
		}
		s.insert(mi1);
		
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		int mi2 = minn(v, mi1, gano);
		s.insert(mi2);
		
		int mi3 = minn(v, ma1, gano);
		s.insert(mi3);
		s.insert(v[0]);
		s.insert(x);
		s.insert(y);
		
		if (gano == 2)
			cout << "-1" << endl;
		else if (gano == 0)
		{
			int r = 0;
			int k = 1;
			
			while (true)
			{
				r = k++;
				
				if (s.find(r) == s.end())
					break;
					
				if (r > 52)
					break;
			}
			
			if (r > 52)
				cout << "-1" << endl;
			else
				cout << r << endl;				
		}
		else
		{
			int r = 0;
			int k = 1;
			
			while (true)
			{
				r = v[0]+k++;
				
				if (s.find(r) == s.end())
					break;
					
				if (r > 52)
					break;
			}
			
			if (r > 52)
				cout << "-1" << endl;
			else
				cout << r << endl;			
		}
		

		
	}
	return 0;
}
