#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

bool is_primo(int n)
{
	for (int i = 2; i < ceil(sqrt(n)) + 1; i++)
		if (n % i == 0) return false;
	
	return true;
}

vector < int > get_primos(int n)
{
	int i, t = 0;
	vector < int > res;
	
	res.push_back(2);
	for (i = 3; t < n; i++)
		if (is_primo(i))
		{
			res.push_back(i);
			t++;
		}
	
	return res;
}

int main()
{
	int i, j, n, sz;
	string s;
	stringstream ss;
	
	getline(cin, s);
	ss << s;
	ss >> n;
	for (int k = 0; k < n; k++)
	{
		string s, rs;
		getline(cin, s);
		rs = s;
		reverse(rs.begin(), rs.end());
		sz = s.size();
		
		vector < int > primos = get_primos(sz);
		vector < char > res(primos[sz - 1], ' ');
		
		for (i = 0; i < sz; i++)
			res[primos[i] - 1] = (rs[i] == ' ' ? '*' : rs[i]);
		
		int t = 0;
		int e = 0;
		bool salir = false;
		for (i = 0; i < primos[sz - 1]; i++)
		{
			if (s[i] == ' ') {e++; continue;}
			
			for (j = 0; j < i + 1 - e; j++)
			{
				while (t < primos[sz - 1] && res[t] != ' ') 
					t++;
				if (t < primos[sz - 1])
					res[t] = s[i];
				else
					salir = true;
				
				if (salir) break;
			}
			
			if (salir) break;
		}
		

		for (i = 0; i < primos[sz - 1]; i++)
			cout << (res[i] == '*' ? ' ' : res[i]);
		cout << endl;
	}
	
	return 0;
}
