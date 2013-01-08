#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void red(vector< vector<char> > &v, int &count, int row, int col, int caso)
{
	if (count % 4 != 0){
		cout<<"Case #"<<caso<<":\nImpossible\n";
		return;
	}
	for (int f=1; f<=row; ++f){
		for (int c = 1; c<=col; ++c){
			if (v[f][c] == '#'){
				if (v[f][c+1] == '#' && v[f+1][c] == '#' && v[f+1][c+1] == '#'){
					v[f][c] = '/';
					v[f][c+1] = '\\';
					v[f+1][c] = '\\';
					v[f+1][c+1] = '/';
					count -= 4;
				}
			}
		}
	}
	if (count == 0){
		cout<<"Case #"<<caso<<":\n";
		for (int f=1; f<=row; ++f){
			for (int c = 1; c<=col; ++c){
				cout<<v[f][c];
			}
			cout<<'\n';
		}
	}
	else cout<<"Case #"<<caso<<":\nImpossible\n";
	
}
	
int main() {

	int t, r, c;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>r>>c;
		char aux;
		int count = 0;
		vector< vector<char> > v(r+2, vector<char>(c+2));
		for (int f=1; f<=r; ++f){
			for (int co = 1; co<=c; ++co){
				cin>>aux;
				v[f][co] = aux;
				if (aux == '#') count++;
			}
		}
		red(v, count, r, c, i+1);
	}
	return 0;
}


