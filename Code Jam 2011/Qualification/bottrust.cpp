#include <iostream>

using namespace std;

void camino(vector<char> &robots, vector<int> &botones)
{
	int tiempo;
	int poso = 1, posb = 1; //posiciones de los robots orange y blue
	int i=0;
	while (true){
		
	}
	
}

int main() {
	int t, n;
	char r;
	int b;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>n;
		vector<char> robots(n);
		vector<int> botones(n);
		for (int j=0; j<n; ++j){
			cin>>r>>b;
			robots(j) = r;
			botones(j) = b;
		}
		camino(robots, botones);
	}
	return 0;
}

