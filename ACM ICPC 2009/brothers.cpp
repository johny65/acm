//resuelto!!

#include <iostream>
#include <vector>

using namespace std;

void magia(vector< vector<int> > &v, int n, int r, int c, int k)
{
	vector< vector<int> > viejo = v;
	int heir, amatar;
	for (int i=0; i<k; i++){ //número de batallas
		for (int f=1; f<=r; f++){ //filas
			for (int cc=1; cc<=c; cc++){ //columnas
				heir = viejo[f][cc];
				if (heir == n-1) amatar=0;
				else amatar = heir+1;
				
				//ver a quién mata
				//arriba
				if (viejo[f-1][cc] == amatar) v[f-1][cc] = heir;
				
				//abajo
				if (viejo[f+1][cc] == amatar) v[f+1][cc] = heir;
				
				//derecha
				if (viejo[f][cc+1] == amatar) v[f][cc+1] = heir;
				
				//izquierda
				if (viejo[f][cc-1] == amatar) v[f][cc-1] = heir;
			}
		} //terminé de recorrer una batalla
		
		viejo = v; //actualizo el tablero
	}
	
	//mostrar
	for (int f=1; f<=r; f++){
		for (int col=1; col<=c; col++){
			cout<<viejo[f][col];
			if (col != c) cout<<" ";
		}
		cout<<'\n';
	}
	
	return;
}
			
int main()
{
	int n, r, c, k;
	scanf("%d %d %d %d\n", &n, &r, &c, &k);
	while ( !(n == 0 && r == 0 && c == 0 && k == 0) ){
		vector<int> blanco(c+2, -1);
		vector< vector<int> > reino(r+2, blanco);
			
		for (int f=1; f<=r; f++){
			for (int col=1; col<=c; col++){
				cin>>reino[f][col];
			}
		}
		
		magia(reino, n, r, c, k);
		
		//mostrar
		/*
		for (int f=1; f<=r; f++){
		for (int col=1; col<=c; col++){
			cout<<reino[f][col];
		}
		cout<<'\n';
		}*/

		scanf("%d %d %d %d\n", &n, &r, &c, &k);
	}

	return 0;
}
