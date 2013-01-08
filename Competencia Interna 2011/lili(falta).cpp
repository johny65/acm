#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

class barco {
public:
	int x, y;
};

void bomba(vector<barco> &b)
{
	double xx = 0, yy = 0;
	for (int i=0; i<b.size(); ++i){
		xx += b[i].x;
		yy += b[i].y;
	}
	xx /= b.size();
	yy /= b.size();
	
	double mayor = -1;//numeric_limits<float>().max();
	for (int i=0; i<b.size(); ++i){
		double f = sqrt((b[i].x - xx)*(b[i].x - xx) + (b[i].y - yy)*(b[i].y - yy));
		//cout<<f<<endl;
		if (f > mayor){
			mayor = f;
		}
	}
	cout<<"xx: "<<xx<<" yy: "<<yy<<endl;
	cout<<"sol: "<<floor(mayor)<<endl;
	
	double mayor2 = -1;
	for (int i=0; i<b.size(); ++i){
		for (int j=0; j<b.size(); ++j){
			double f = sqrt((b[i].x - b[j].x)*(b[i].x - b[j].x) + (b[i].y - b[j].y)*(b[i].y - b[j].y));
			if (f > mayor2) mayor2 = f;
			//cout<<floor(f)<<endl;
		}
	}
	cout<<mayor2<<endl;
}


int main(int argc, char *argv[]) {

	int n, x, y;
	while (cin>>n && n != 0){
		vector<barco> b(n);
		for (int i=0; i<n; ++i){
			cin>>x>>y;
			barco nuevo; nuevo.x = x; nuevo.y = y;
			b[i] = nuevo;
		}
		bomba(b);
	}
	return 0;
}

