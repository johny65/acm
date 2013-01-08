#include <iostream>
#include <vector>
#include <set>
using namespace std;

class ticket {
public:
	ticket(int n, int x, int y, int z) {
		nro = n;
		s.insert(x);
		s.insert(y);
		s.insert(z);
	}
	
	bool estan(int x, int y, int z) {
		return ( (s.find(x) != s.end()) && (s.find(y) != s.end()) && (s.find(z) != s.end()));
	}
	int nro;
private:
	set<int> s;
	
	
};

int main(int argc, char *argv[]) {
	int c, t;
	int n, x, y, z;
	vector<ticket> v;
	int prize = 0;
	bool flag;
	int j;
	
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> t;
		flag = false;
		v.clear();
		for (j = 0; j < t; j++) {
			cin >> n >> x >> y >> z;
			ticket t(n, x, y, z);
			v.push_back(t);
		}
		
		prize += t;
		
		cin >> x >> y >> z;
		
		
		for (j = 0; j < v.size() && !flag; j++) {
			if (v[j].estan(x, y, z)) {
				flag = true;
			}
		}
		
		if (flag) {
			cout << v[j-1].nro << " " << prize << endl;
			prize = 0;
		}
		else {
			cout << "0 0" << endl;
		}
		
	} 
	
	
	
	return 0;
}

