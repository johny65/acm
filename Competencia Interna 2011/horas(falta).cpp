#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class materia {
public:
	int horas, numcorr, cantcorr;
	bool esta;
	bool operator<(const materia &m) const {
		if (horas > m.horas)
			return true;
		if (horas == m.horas && cantcorr < m.cantcorr)
			return true;
		return false;
	}
};

int sumacor(materia &m, vector<materia> &v){
	if (m.numcorr == 0) //no tiene correlativas
		return 0;
	else {
		v[m.numcorr-1].esta = true;
		return v[m.numcorr-1].horas + sumacor(v[m.numcorr-1], v);
	}
}

int cantc(materia &m, vector<materia> &v){
	if (m.numcorr == 0) //no tiene correlativas
		return 0;
	else
		return 1 + cantc(v[m.numcorr-1], v);
}

void dale(vector<materia> &v, int h)
{
	sort(v.begin(), v.end());
	int suma = 0, cant = 0;
	for (int i=0; i<v.size(); ++i){
		if (!v[i].esta){
			suma += v[i].horas;
			v[i].esta = true;
			cant++;
			suma += sumacor(v[i], v);
			cant += v[i].cantcorr;
			if (suma >= h)
				break;
		}
	}
	
	cout<<cant<<endl;
}

int main(int argc, char *argv[]) {
	
	int n, h;
	int hs, c;
	while (cin>>n>>h && n != 0){
		vector<materia> v(n);
		for (int i=0; i<n; ++i){ //leer horas
			cin>>hs;
			materia m; m.horas = hs; m.esta = false;
			v[i] = m;
		}
		for (int i=0; i<n; ++i){ //leer correlatividades
			cin>>c;
			v[i].numcorr = c;
			if (c == 0)
				v[i].cantcorr = 0;
			
		}
		//acomodar corre
		
		for (int i=0; i<n; ++i){
			if (v[i].numcorr != 0){
				v[i].cantcorr = cantc(v[i], v);
			}
		}
		dale(v, h);
	}
	return 0;
}

