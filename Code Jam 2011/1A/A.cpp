#include <iostream>
#include <cmath>

using namespace std;

void estadisticar(double n, int pd, int pg, int caso)
{
	if (pg == 100 && pd != 100){
		cout<<"Case #"<<caso<<": Broken\n";
		return;
	}
	if (pg == 0 && pd != 0){
		cout<<"Case #"<<caso<<": Broken\n";
		return;
	}
	double d = 1; //empiezo desde hasta n
	while (d <= n){
		double porc = d*pd/100;
		//ver si es entero
		if (porc == floor(porc)){
			cout<<"Case #"<<caso<<": Possible\n";
			return;
		}
		d++;
	}
	cout<<"Case #"<<caso<<": Broken\n";
}
	

int main(){
	int t, pd, pg;
	double n;
	cin>>t;
	for (int i=0; i<t; ++i){
		cin>>n>>pd>>pg;
		estadisticar(n, pd, pg, i+1);
	}
	return 0;
}
