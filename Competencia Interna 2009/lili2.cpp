#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

#define pi 3.1415926535897932384626433832795

using namespace std;

int cantbarcosl=0, cantbarcosb=0;

class barco {
public:
	int x, y, r;
	char reino;
	bool hundido;
	barco(char lob, int xc, int yc, int radio){
		x = xc;
		y = yc;
		r = radio;
		reino = lob;
		hundido = false;
	}
};

class tiro {
public:
	int x, y, ang;
	tiro(int xc, int yc, int a){
		x = xc;
		y = yc;
		ang = a;
	}
};

bool esdelbarco(int xb, int yb, int rb, int xt, int yt)
{
	//devuelve si el origen del tiro está adentro del barco
	return (pow((xt-xb), 2)+pow((yt-yb), 2) <= pow(rb, 2));
}

bool lepega(double xt, double yt, double xth, double yth, int xb, int yb, int rb, double &distancia)
{
	double dirx, diry; //dirección del tiro
	dirx = xth-xt;
	diry = yth-yt;
	//lo normalizo
	double dir = sqrt(dirx*dirx + diry*diry);
	dirx/=dir;
	diry/=dir;
	
	double tacx, tacy; //vector desde el origen del tiro hasta el centro del barco
	tacx = xb-xt;
	tacy = yb-yt;
	double tac = sqrt(tacx*tacx + tacy*tacy);
	
	double proy = dirx*tacx + diry*tacy; //proyección de tac sobre el segmento del tiro
	
	double ddd = rb*rb - tac*tac + proy*proy;
	if (ddd < 0) //no le pega
		return false;
	
	double dist = proy - sqrt(ddd);
	if (dist > 2000) //no alcanza a pegarle
		return false;
	else {
		//if (dist < 0) return false;
		
		double tmpx, tmpy;
		tmpx = xt + dist*dirx;
		tmpy = yt + dist*diry;
		double t2x, t2y;
		t2x = tmpx-xb;
		t2y = tmpy-yb;
		double t2 = sqrt(t2x*t2x + t2y*t2y);
		if (t2 > rb + 1) return false;
		
		distancia = dist;
		return true;
	}
}

void guerra(vector<barco> &barcos, vector<tiro> &tiros)
{
	//recorrer los tiros
	for (int i=0; i<tiros.size(); i++){
		int &xt=tiros[i].x;
		int &yt=tiros[i].y;
		//ver de qué barco es el tiro
		int j=0;
		while (j<barcos.size()){
			if (esdelbarco(barcos[j].x, barcos[j].y, barcos[j].r, xt, yt))
				break;
			j++;
		}
		
		//si el barco está hundido, pasar al siguiente tiro
		if (barcos[j].hundido) continue;
		
		//ver a quién le pega:
		//guardo todos los barcos a los que le pegó, y a qué distancia
		map<barco*, double> mapa;
		
		//calcular el punto hasta donde llega el tiro (2000 metros)
		double xth, yth;
		if (tiros[i].ang == 0){
			xth = xt+2000;
			yth = yt;
		}
		else if (tiros[i].ang == 90){
			xth = xt;
			yth = yt + 2000;
		}
		else if (tiros[i].ang == 180){
			xth = xt-2000;
			yth = yt;
		}
		else if (tiros[i].ang == 270){
			xth = xt;
			yth = yt-2000;
		}
		else {		
			double aaa = tiros[i].ang*pi/180.0;
			xth = xt + 2000*cos(aaa);
			yth = yt + 2000*sin(aaa);
		}
		
		//revisar cada barco y ver a cuál le pegó
		for (int h=0; h<barcos.size(); h++){
			if (h != j){ //un barco no se puede pegar a sí mismo
				if (barcos[h].hundido) continue; //si el barco está hundido no le puede pegar...
				double dist;
				if (lepega(xt, yt, xth, yth, barcos[h].x, barcos[h].y, barcos[h].r, dist)){
					//le pegó, guardar ese barco
					mapa.insert(pair<barco*, double>(&barcos[h], dist));
				}
			}
		}
		
		//ahora en mapa tengo todos los barcos a los que le pegó
		//ver cuál fue el primero al que le pegó
		double distmin = 10000000;
		map<barco*, double>::iterator itmin = mapa.end();
		for (map<barco*, double>::iterator it = mapa.begin(); it != mapa.end(); it++){
			if (it->second < distmin){
				distmin = it->second;
				itmin = it;
			}
		}
		
		//hundir al que le pegó (si es que le pegó a alguno)
		if (itmin != mapa.end()){
			(*(itmin->first)).hundido = true;
			if ((*(itmin->first)).reino == 'L')
				cantbarcosl--;
			else
				cantbarcosb--;
		}
			
		//antes de pasar al siguiente tiro, ver si alguna flota ya no murió
		if (cantbarcosb == 0){
			cout<<"LILLIPUT WIN\n";
			return;
		}
		else if (cantbarcosl == 0){
			cout<<"BLEFUSCU WIN\n";
			return;
		}
		
	} //pasar al siguiente tiro
	
	if (cantbarcosb == 0){
		cout<<"LILLIPUT WIN\n";
		return;
	}
	else if (cantbarcosl == 0){
		cout<<"BLEFUSCU WIN\n";
		return;
	}
	//si acá todavía hay barcos de las 2 flotas, es un empate
	else if (cantbarcosb != 0 && cantbarcosl != 0)
		cout<<"MORE BLOOD NEEDED\n";
		
	return;
	
}

int main()
{
	int n, f;
	char lb;
	int x, y, r;
	
	scanf("%i %i\n", &n, &f);
	while (n != 0 || f != 0){
		//barcos
		vector<barco> barcos;
		int i;
		for (i=0; i<n; i++){
			cin>>lb>>x>>y>>r;
			barcos.push_back(barco(lb, x, y, r));
			if (lb == 'L')
				cantbarcosl++;
			else
				cantbarcosb++;
		}
		//tiros
		vector<tiro> tiros;
		for (i=0; i<f; i++){
	 		cin>>x>>y>>r;
			tiros.push_back(tiro(x, y, r));
		}
		guerra(barcos, tiros);
		cantbarcosb = cantbarcosl = 0;
		scanf("%i %i\n", &n, &f);
	}
	return 0;
}
