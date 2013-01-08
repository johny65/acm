#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;

bool todos_iguales(int a, int b, int c)
{
	return (a == b && b == c);
}

void ver(vector<int> &v)
{
	int a = v[0], b = v[1], c = v[2];
	if (a == b && b == c && a != 13){
		cout<<a+1<<" "<<b+1<<" "<<c+1<<endl;
		return;
	}
	if (a == b && b == c && a == 13){
		cout<<"*\n";
		return;
	}
	if (a != b && b != c && a != c){
		cout<<"1 1 2\n";
		return;
	}
	
	
	if (v[0] != v[1])
		swap(v[0], v[2]);
	
	if (v[0] == 13 && v[1] == 13 && v[2] == 12){
		cout<<"1 1 1\n";
		return;
	}
	
	while (true){
		
		if (v[2] != 13) v[2]++;
		else {
			v[1]++;
			v[0]++;
			v[2] = 1;
			if (v[1] == 14){
				v[0]++;
				v[1] = 1;
				if (v[0] > 14) v[0] = 1;
			}
		}
		if (!todos_iguales(v[0], v[1], v[2])){
			sort(v.begin(), v.end());
			cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
			break;
		}
	}
	
	
		
}
		

int main(){

	int a, b, c;
	while (cin>>a>>b>>c && a != 0 && b != 0 && c != 0){
		vector<int> v(3);
		v[0] = a;
		v[1] = b;
		v[2] = c;
		sort(v.begin(), v.end());
		ver(v);
	}
	return 0;
	
}
