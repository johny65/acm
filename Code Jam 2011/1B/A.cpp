#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void calcrpi(vector<string> &v, int n, int caso)
{
	vector<double> wp(n), owp(n), oowp(n), rpi(n);
	vector<int> jugados(n, 0);
	vector< vector<int> > conquien(n);
	for (int f=0; f<n; ++f){
		int ganados = 0, perdidos = 0;
		for (int c=0; c<n; ++c){
			if (v[f][c] == '1') ganados++;
			else if (v[f][c] == '0') perdidos ++;
			if (v[f][c] != '.'){
				conquien[f].push_back(c);
				jugados[f]++;
			}
		}
		wp[f] = ganados*1.0/jugados[f];
	}
	
	//ver owp
	for (int f=0; f<n; ++f){
		double owpaux = 0;
		for (int i=0; i<conquien[f].size(); ++i){
			int oponente = conquien[f][i];
			double aux = wp[oponente];
			aux *= jugados[oponente];
			if (v[oponente][f] == '1'){
				aux -= 1;
			}
			aux /= (jugados[oponente]-1);
			owpaux += aux;
		}
		owp[f] = owpaux / conquien[f].size();
	}
	
	//ver oowp
	for (int f=0; f<n; ++f){
		double oowpaux = 0;
		for (int i=0; i<conquien[f].size(); ++i){
			int oponente = conquien[f][i];
			oowpaux += owp[oponente];
		}
		oowp[f] = oowpaux / conquien[f].size();
		double RPI = 0.25 * wp[f] + 0.50 * owp[f] + 0.25 * oowp[f];
		rpi[f] = RPI;
	}
	
	//for (int f=0; f<n; ++f){
		//cout<<"Case #"<<f<<": "<<rpi[f]<<'\n';
		//cout<<"WP: "<<wp[f]<<'\n';
		//cout<<"OWP: "<<owp[f]<<'\n';
		//cout<<"OOWP: "<<oowp[f]<<'\n';
	//}
	
	cout<<"Case #"<<caso<<":\n";
	for (int f=0; f<n; ++f){
		cout<<setprecision(13)<<rpi[f]<<'\n';
	}
}

int main(){
	int t, n;
	cin>>t;
	string s;
	for (int i=0; i<t; ++i){
		cin>>n;
		vector<string> v(n);
		for (int j=0; j<n; ++j){
			cin>>s;
			v[j] = s;
		}
		calcrpi(v, n, i+1);
	}
	return 0;
}
