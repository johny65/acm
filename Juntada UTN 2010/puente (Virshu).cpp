#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[]) {
	
	
	int casos, personas;
	cin >> casos;
	while (cin >> personas)
	{
		int sum=0;
		//cin >> personas;
		vector<int> g;
		int aux;
		for (int i=0; i<personas; i++)
		{	cin >> aux;
			g.push_back(aux);
		}
			
		sort(g.begin(), g.end());
		
		
		
		if (g.size() == 0)
			sum = 0;
		else if (g.size()==1)
			sum=g[0];
		else{
			int p = g[0];
			g.erase(g.begin());
			int s = g[0];
			g.erase(g.begin());
			sum = s;
			while (g.size() > 0)
			{
				if (g.size() > 1)
				{
					sum+=p;
					g.erase(g.begin());
					sum += g[0];
					g.erase(g.begin());
				
					if (g.size() >=1)
					{
						sum += s+s;
					}
				}
				else
				{
					sum+=p;
					sum+=g[0];
					g.erase(g.begin());
				
				}
				cout<< sum<<endl;
			}
			
			if (personas%2 == 0)
				sum += s+s;
		
		}
		cout<<sum<<endl;
		casos--;
	}

	return 0;
}

