#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool menor(string s1, string s2)
{
	bool pri; //true: s1, false: s2
	string larga, corta;
	if (s1.length() < s2.length()){
		larga = s2; 
		corta = s1;
		pri = false;
	}
	else {
		larga = s1;
		corta = s2;
		pri = true;
	}
	
	for (int i = 0; i<larga.length(); ++i){
		int j = i % corta.length();
		if (larga[i] < corta[j])
			return pri;
		else if (larga[i] > corta[j])
			return !pri;
	}
	return !pri;
}

int main()
{
	int n, m;
	string s;
	vector<string> v;
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>m;
		for (int j=0; j<m; ++j){
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), menor);
		for (int j=0; j<v.size(); ++j)
			cout<<v[j];
		cout<<'\n';
		v.clear();
	}
	return 0;
}
