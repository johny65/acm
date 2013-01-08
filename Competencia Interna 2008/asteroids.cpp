#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct asteroide {
	int x, y, r;
};

void armar_punto(float ang, asteroide a, float &x, float &y, int navex, int navey)
{
	if (ang < 1.57){ //apunta hacia mi primer cuadrante
	    x = abs((a.x-navex)) + 2*a.r;
	    y = tan(ang)*x;
	    x+=navex;
	    y+=navey;
	}
	else if (ang == 1.57){ //apunta para arriba
		x = navex;
		y = abs((a.y-navey)) + 2*a.r + navey;
	}
	else if (ang < 3.141 && ang > 1.57){ //apunta hacia mi segundo cuadrante
	    x = -(abs((a.x-navex)) + 2*a.r);
	    y = tan(ang)*x;
	    x+=navex;
	    y+=navey;
	}
	else if (ang == 3.141){ //apunta a la izquierda
	    y = navey;
	    x = -(abs((a.x-navex)) + 2*a.r) + navex;
	}
	else if (ang > 3.141 && ang < 4.712){ //apunta hacia mi tercer cuadrante
	    x = -(abs((a.x-navex)) + 2*a.r);
	    y = tan(ang)*x;
	    x+=navex;
	    y+=navey;
	}
	else if (ang == 4.712){ //apunta para abajo
	    x = navex;
	    y = -(abs((a.y-navey)) + 2*a.r) + navey;
	}
	else if (ang > 4.712 && ang < 6.283){ //apunta hacia mi cuarto cuadrante
		x = abs((a.x-navex)) + 2*a.r;
		y = tan(ang)*x;
		x+=navex;
	    y+=navey;
	}
	else if (ang == 6.283 || ang == 0){ //apunta a la derecha
	    y = navey;
	    x = (abs((a.x-navex)) + 2*a.r) + navex;
	}
}

void armar_recta(float x1, float y1, float x2, float y2, float &a, float &b, float &c)
{
	a = -(y1-y2);
	b = x1-x2;
	c = b*(-y1) + a*(-x1);
}

bool le_pega(float ar, float br, float cr, float ac, float bc, float cc)
{
	float a, b, c, disc;
	a = pow((-br)/ar, 2) + 1;
	b = 2*((-cr)/ar)*((-br)/ar) + ac*((-br)/ar) + bc; 
	c = pow((-cr)/ar, 2) + ac*((-cr)/ar) + cc;
	disc = b*b - 4*a*c;
	if (disc >= 0) return true;
	else return false;
}

void calcular(const vector<asteroide> &v, const vector<float> &orient, int n, int m, int navex, int navey, vector<int> &res)
{
	//n: cantidad de asteroides
	//m: cantidad de orientaciones

	for (int i=0; i<n; i++){
		//ver si está adentro del asteroide
		if (pow((navex-v[i].x), 2)+pow((navey-v[i].y), 2) <= pow(v[i].r, 2)){
			res.push_back(-1);
			return;
		}
	}
	
	int mayorpunt = 0;
	//revisar cada ángulo
	for (int i=0; i<m; i++){
		int punt = 0;
		for (int j=0; j<n; j++){ //revisar cada asteroide
		    float x, y;
		    armar_punto(orient[i], v[j], x, y, navex, navey);
			float ar, br, cr, ac, bc, cc;
			armar_recta(navex, navey, x, y, ar, br, cr);
			ac = -2*v[j].x;
			bc = -2*v[j].y;
			cc = pow(v[j].x, 2) + pow(v[j].y, 2) - pow(v[j].r, 2);
			bool boom = le_pega(ar, br, cr, ac, bc, cc);
			if (boom)
				punt+=100*v[j].r;
		}
		if (punt > mayorpunt)
			mayorpunt = punt;
	}
	res.push_back(mayorpunt);
}

int main()
{
	int n, m, navex, navey;
	vector<asteroide> v(100);
	vector<float> orient(50);
	vector<int> res;
	cin>>n>>m;
	while (n != 0){
		for (int i=0; i < n; i++){
			int a, b, c;
			cin>>a>>b>>c;
			asteroide t;
			t.x = a;
			t.y = b;
			t.r = c;
			v[i]=t;
		}
		cin>>navex>>navey;
		for (int i=0; i < m; i++){
			float t;
			cin>>t;
			orient[i]=t;
		}
		calcular(v, orient, n, m, navex, navey, res);
		cin>>n>>m;
	}
	
	//mostrar resultados:

	for (int i=0; i<res.size(); i++){
		if (res[i] == -1)
		    cout<<"KBOOM!\n";
		else
		    cout<<res[i]<<'\n';
	}
	
	return 0;
}
