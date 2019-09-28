#include <iostream>
#include <string>
#include <set>

vector<int> res;

void resolver(vector<string> &song, vector<string> &art)
{
	sum=0;
	set<string> gold;
	for (unsigned int i=0; i<song.size(); i++){
		string vi = v[i];
		for (int j=0; j<vi.length(); j++){
			string b = vi[j];
			
		
	

int main()
{
	int n;
	string l;
	vector<string> song, art;
	cin>>n;
	cin.ignore();
	while (n != 0){
		for (int i=0; i<n; i++){
			getline(cin, l);
			song.push_back(l);
			getline(cin, l);
			art.push_back(l);
		}
		resolver(song, art);
		cin>>n;
	}
	
	for (unsigned int i=0; i<res.size(); i++){
		cout<<res[i]<<'\n';
	}
	
	return 0;
}
