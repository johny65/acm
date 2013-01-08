//145 Gondwanaland Telecom:
//http://uva.onlinejudge.org/external/1/145.html
//Accepted
//C++ 0.008 2011-09-28 02:17:53

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class hora {
public:
	int h, m;
	int id;
	hora(int h, int m) : h(h), m(m) {
		id = 60*h + m;
	}
	bool entre(hora &h1, hora &h2){
		return (h1.id <= id && id <= h2.id);
	}
	int diff(hora &h2){
		return h2.id - id;
	}
	bool operator<(hora &h2){
		return id < h2.id;
	}
};

hora day1(8, 0);
hora day2(18, 0);
hora eve1(18, 0);
hora eve2(22, 0);
hora nig1(22, 0);
hora nig2(32, 0);

void calcular(hora &desde, hora &hasta, char cs, string num)
{
	int d = 0, t = 0, n = 0;
	
	//ver si mañana
	if (desde.entre(day1, day2)){
		//cout<<"de día\n";
		if (hasta.entre(day1, day2)){ //todo de día
			if (desde < hasta)
				d = desde.diff(hasta);
			else { //dio toda una vuelta
				d = desde.diff(day2);
				d += day1.diff(hasta);
				t = 4*60;
				n = 10*60;
			}
		}
		else if (hasta.entre(eve1, eve2)){
			d = desde.diff(day2);
			t += eve1.diff(hasta);
		}
		else if (hasta.entre(nig1, nig2)){
			d = desde.diff(day2);
			n += nig1.diff(hasta);
			t += 4*60; //toda la tarde
		}
	}
	//ver si tarde
	if (desde.entre(eve1, eve2)){
		//cout<<"de tarde\n";
		if (hasta.entre(eve1, eve2)){ //todo de tarde
			if (desde < hasta)
				t = desde.diff(hasta);
			else { //dio toda una vuelta
				t = desde.diff(eve2);
				t += eve1.diff(hasta);
				d = 10*60;
				n = 10*60;
			}
		}
		else if (hasta.entre(nig1, nig2)){
			t = desde.diff(eve2);
			n += nig1.diff(hasta);
		}
		else if (hasta.entre(day1, day2)){
			t = desde.diff(nig2);
			d += day1.diff(hasta);
			n += 10*60; //toda la noche
		}
	}
	
	//ver si noche
	if (desde.entre(nig1, nig2)){
		//cout<<"de noche\n";
		if (hasta.entre(nig1, nig2)){ //todo de noche
			if (desde < hasta)
				n = desde.diff(hasta);
			else { //dio toda una vuelta
				n = desde.diff(nig2);
				n += nig1.diff(hasta);
				d = 10*60;
				t = 4*60;
			}
		}
		else if (hasta.entre(day1, day2)){
			n = desde.diff(nig2);
			d += day1.diff(hasta);
		}
		else if (hasta.entre(eve1, eve2)){
			n = desde.diff(nig2);
			t += eve1.diff(hasta);
			d += 10*60; //todo el día
		}
	}
	
	double costo;
	switch (cs){
		case 'A':
			costo = d*0.10 + t*0.06 + n*0.02;
			break;
		case 'B':
			costo = d*0.25 + t*0.15 + n*0.05;
			break;
		case 'C':
			costo = d*0.53 + t*0.33 + n*0.13;
			break;
		case 'D':
			costo = d*0.87 + t*0.47 + n*0.17;
			break;
		case 'E':
			costo = d*1.44 + t*0.80 + n*0.30;
	}
	cout<<setw(10)<<num<<setw(6)<<d<<setw(6)<<t<<setw(6)<<n<<setw(3)<<cs;
	cout<<setw(8)<<setprecision(2)<<fixed<<costo<<'\n';

}

int main(){
	char cs;
	int h1, m1, h2, m2;
	string num;
	while (cin>>cs && cs != '#'){
		cin>>num>>h1>>m1>>h2>>m2;
		if (h1 < 8) h1+=24;
		if (h2 < 8) h2+=24;
		hora desde(h1, m1);
		hora hasta(h2, m2);
		calcular(desde, hasta, cs, num);
	}
	return 0;
}
