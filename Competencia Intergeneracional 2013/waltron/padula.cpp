#include <iostream>
#include <vector>
using namespace std;

double cross( double x1, double y1, double x2, double y2 ) {
	return x1*y2 - x2*y1;
} 


int main(int argc, char *argv[]) {
	int t, n;
	cin>>t;
	for(int i=0;i<t;i++) { 
		cin>>n;
		vector<double> x(n), y(n);
		for(int j=0;j<n;j++) 
			cin>>x[j]>>y[j];
		vector<double> xt(3), yt(3);
		for(int j=0;j<3;j++) 
			cin>>xt[j]>>yt[j];
			
		int r = 0;
		for(int j=0;j<n;j++) {
			double c1 = cross( xt[1]-xt[0], yt[1]-yt[0], x[j]-xt[0], y[j]-yt[0] );
			double c2 = cross( xt[2]-xt[1], yt[2]-yt[1], x[j]-xt[1], y[j]-yt[1] );
			double c3 = cross( xt[0]-xt[2], yt[0]-yt[2], x[j]-xt[2], y[j]-yt[2] );
			if( c1 >= 0 && c2 >= 0 && c3 >= 0 )
				r++;
			if( c1 <= 0 && c2 <= 0 && c3 <= 0 )
				r++;
		}
		cout<<r<<endl;
	}
	return 0;
}

