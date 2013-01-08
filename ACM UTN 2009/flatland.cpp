#include <iostream>
#include <cmath>
using namespace std;

bool espot2(double n)
{
	
	double x = log(n)/log(double(2));
	
	return x == int(x);
	
	/*int i=1;
	while (true){
		double po = pow(double(2), i);
		i++;
		if (po > n) return false;
		if (po == n) return true;		
	}*/
}

void coord(unsigned int n, int &x, int &y)
{
	/*float i=1;
	while (true){
		double t = n/i;
		if (espot2(t)){
			x=t; y=i;
			return;
		}
		i+=2;
	}*/
	
	int i = 0;
	
	while (true) {
		if ( int((n/pow(double(2), i))) % 2 == 1) {
			x = i;
			y = n/pow(double(2),i);
			return;
		}
		else i++;
	}
	
	
}

void calc(int n, int m)
{
	int x1, y1, x2, y2;
	coord(n, x1, y1);
	coord(m, x2, y2);
	int pasos;
	pasos = abs(y1-y2)/2 + abs(x1-x2);
		
		//abs( log(double(x1))/log(double(2)) - log(double(x2))/log(double(2)) );
	
	cout << "The distance between " << n << " and " << m << " is " << pasos << "." << endl;
}

int main(int argc, char *argv[]) {
	int n, m;
	int x, y, z, a;
	
	cin>>n>>m;
	

	
	while (n!=0 && m!=0){
		calc(n, m);
		cin>>n>>m;
	}
	
	return 0;
}


