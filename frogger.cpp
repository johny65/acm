#include <iostream>
#include <vector>
#include <string>

using namespace std;

string res;

bool calcular_col(const vector< vector<int> > &m, int c)
{
	//matriz m de 8x10
	vector< vector<int> > m2 = m;
	int possapo=-1;
	//empezar a mover el sapo (sapo representado por -1)
	if (m2[possapo+1][c] != 0) //chocó
		return false;
	else {
		m2[possapo+1][c] = -1;
		possapo++;
	}

	while (possapo != 7){

		//mover los autos
		for (int f=possapo; f<4; f++){ //filas 1-4 se mueven a la izquierda
			vector<int> cambios(10,0);
			if (f==possapo) cambios[c] = -1;
			for (int j=0; j<10; j++){
				if (m2[f][j] != 0 && m2[f][j] != -1){ //hay un auto, moverlo
					int np = j-m2[f][j]; //nueva posición
					if (np < 0) np = 10 + np; //rotar si se pasa de largo
					if (m2[f][np] == -1){ //chocó al sapo
						return false;
					}
					cambios[np]=m2[f][j];
				}
			}
			m2[f] = cambios;
		}
		for (int f=4; f<8; f++){ //filas 5-8 se mueven a la derecha
			if (f<possapo) break;
			vector<int> cambios(10,0);
			if (f==possapo) cambios[c] = -1;
			for (int j=0; j<10; j++){
				if (m2[f][j] != 0 && m2[f][j] != -1){ //hay un auto, moverlo
					int np = j+m2[f][j]; //nueva posición
					if (np > 9) np = np - 10; //rotar si se pasa de largo
					if (m2[f][np] == -1){ //chocó al sapo
						return false;
					}
					cambios[np]=m2[f][j];
				}
			}
			m2[f] = cambios;
		}
		
		//mover el sapo
		if (m2[possapo+1][c] != 0) //chocó
			return false;
		else {
			m2[possapo+1][c] = -1;
			m2[possapo][c] = 0;
			possapo++;
		}
		
	}
	return true;
} //fin calcular_col

void calcular(const vector< vector<int> > &m)
{
	for (int c=0; c<10; c++){ //ver si puede cruzar en cada columna
		if (calcular_col(m, c)){
			res+="LEFTOVER POSSUM\n";
			return;
		}
	}
	res+="FROGGER\n";

} //fin calcular
		
int main()
{
	string l;
	cin>>l;
	while (l == "START"){
		vector< vector<int> > m(8);
		for (int f=0; f<8; f++){
			for (int c=0; c<10; c++){
				int t;
				cin>>t;
				m[f].push_back(t);
			}
		}
		calcular(m);
		cin>>l; //"END"
		cin>>l;
	}
	//mostrar resultados
	cout<<res;
	return 0;
}
