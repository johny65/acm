#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> sol;

void calcular(vector< vector< vector<bool> > > &M, int n, int m)
{
	vector< vector<bool> > &nueva = M[0];
	vector< vector<bool> > cambiada = M[0];
	int ganador;
	bool salir=false;
	while (true){
		for (int f=0; f<n; f++){
		    for (int c=0; c<m; c++){
				int muertas=0, vivas=0;
				if (!(f-1 < 0) && !(c-1 < 0)){
				    if (nueva[f-1][c-1]) vivas++;
				    else muertas++;
				}
				if (!(f-1 < 0)){
				    if (nueva[f-1][c]) vivas++;
				    else muertas++;
				}
				if (!(f-1 < 0) && !(c+1 > m-1)){
				    if (nueva[f-1][c+1]) vivas++;
				    else muertas++;
				}
				if (!(c-1 < 0)){
				    if (nueva[f][c-1]) vivas++;
				    else muertas++;
				}
				if (!(c+1 > m-1)){
				    if (nueva[f][c+1]) vivas++;
				    else muertas++;
				}
				if (!(f+1 > n-1) && !(c-1 < 0)){
				    if (nueva[f+1][c-1]) vivas++;
				    else muertas++;
				}
				if (!(f+1 > n-1)){
				    if (nueva[f+1][c]) vivas++;
				    else muertas++;
				}
				if (!(f+1 > n-1) && !(c+1 > m-1)){
				    if (nueva[f+1][c+1]) vivas++;
				    else muertas++;
				}

				if (!nueva[f][c]){ //si yo muerta
					if (vivas==3)
				    	cambiada[f][c] = true;
				}
				else { //si yo viva
				    if (vivas != 2 && vivas != 3)
				        cambiada[f][c] = false;
				}
				//terminé de revisar una célula, seguir con las otras
			}
		}
		
		
		/*//-----------------------------------------------------------
		cout<<"\nMatriz resultante luego de una jugada:\n\n";
        for (int f2=0; f2<cambiada.size(); f2++){
	    	for (int c2=0; c2<cambiada[0].size(); c2++){
	       		if (cambiada[f2][c2])
	       			cout<<'X';
				else
		    		cout<<'.';
			}
			cout<<'\n';
		}
		//-----------------------------------------------------------*/
	
	
		for (int k=1; k<M.size(); k++){
		    if (M[k] == cambiada){
				ganador=k;
				sol.push_back(ganador);
				salir=true;
				break;
			}
		}
		if (salir) break;
		nueva = cambiada;
	} //del while

}

int main()
{
	int n, m, g;
	cin>>n>>m>>g;
	while (g != 0){
		vector< vector< vector<bool> > > matrices;
  		string t;
  		cin.ignore();
  		getline(cin, t); //línea en blanco
 		for (int i=0; i<g+1; i++){
			vector< vector<bool> > v;
			//armo la matriz
			for (int k=0; k<n; k++){
                vector<bool> fila;
				string linea;
				cin>>linea;
				for (int j=0; j<m; j++){
				    if (linea[j]=='.')
				        fila.push_back(false);
					else
					    fila.push_back(true);
				}
				v.push_back(fila);
			}
			matrices.push_back(v);
			cin.ignore();
  			getline(cin, t); //línea en blanco
		}
		calcular(matrices, n, m);
        cin>>n>>m>>g;
	}

	//mostrar las soluciones
	for (int i=0; i<sol.size(); i++)
	    cout<<sol[i]<<'\n';
	return 0;
}
