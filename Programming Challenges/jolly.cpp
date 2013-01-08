#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool contar(vector<int> &v)
{
	for (int i=0; i<v.size(); i++){
		if (v[i] != i+1)
			return false;
	}
	return true;
}	

bool esjolly(vector<int> &v, int n)
{
	if (v.size()==1) return true;
	/*set<int> s;
	for (vector<int>::iterator p=v.begin(); p!=v.end(); p++)
		s.insert(*p);
	*/
	
	vector<int> difs(n);
	int i=0;
	while (i<v.size()-1){
		int dif = abs(v[i]-v[i+1]);
		difs[i] = dif;
		i++;
	}
	sort(difs.begin(), difs.end());
	return contar(difs);
}

int main()
{
	int n;
	while (cin>>n){
		vector<int> v(n);
		for (int i=0; i<n; i++){
			int t;
			cin>>t;
			v[i]=t;
		}
		if (esjolly(v, n-1))
			cout<<"Jolly\n";
		else
			cout<<"Not jolly\n";
	}
	return 0;
}
