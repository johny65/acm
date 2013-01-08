#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> dic; //diccionario
vector<string> sopa;

void coord(char letra, int n, int m, int desden, int desdem, int &fila, int &columna)
{
	//busca por filas
	for (int f=desden; f<=n; f++){
		for (int c=desdem+1; c<=m; c++){
			if (sopa[f][c] == letra){
				fila=f;
				columna=c;
				return;
			}
		}
		desdem=0;
	}
	fila = columna = -1; //no está esa letra
}

bool encontrar(string pal, int fila, int columna)
{
	//buscar a la derecha
	int i=0, lon=pal.length();
	int f=fila, c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		c++;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar a la izquierda
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		c--;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar para arriba
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		f--;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar para abajo
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		f++;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar diagonal arriba derecha
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		c++; f--;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar diagonal arriba izquierda
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		c--; f--;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar diagonal abajo derecha
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		c++; f++;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//buscar diagonal abajo izquierda
	i=0; f=fila; c=columna;
	while (sopa[f][c] == pal[i] && i<lon){
		c--; f++;
		i++;
	}
	if (i==lon) //la encontró
		return true;

	//acá no la encontró
	return false;
}

void calcular(int n, int m, int d)
{
	vector<string> estan;
	string a; //palabra actual
	
	//recorro las palabras del diccionario
	for (set<string>::iterator it = dic.begin(); it != dic.end(); it++){
		a=*it;
		char letra=a[0];
		int f, c;
		coord(letra, n, m, 1, 0, f, c); //buscar desde el principio
		while (f != -1 && c != -1){
			if (encontrar(a, f, c)){
				estan.push_back(a);
				break;
			}
			int f2=f, c2=c;
			coord(letra, n, m, f2, c2, f, c); //buscar desde donde llegó antes
		}
	}
	
	if (estan.size() == 0){ //no hay ninguna palabra
		cout<<"-\n";
		return;
	}
		
	for (int i=0; i<estan.size(); i++)
		cout<<estan[i]<<" ";
	cout<<'\n';
	
}

int main(int argc, char *argv[]) {
	int d, n, m;
	string t, guion="-";

	scanf("%i %i %i\n", &d, &n, &m);
	while (d !=0 && n!=0 && m!=0){
		for (int i=0; i<d; i++){
			getline(cin, t);
			dic.insert(t);
		}
		string guiones=guion;
		for (int i=-1; i<m; i++)
			guiones=guiones+guion;
		sopa.push_back(guiones);
		for (int i=0; i<n; i++){
			getline(cin, t);
			t = guion+t;
			t = t+guion;
			sopa.push_back(t);
		}
		sopa.push_back(guiones);
		calcular(n, m, d);
		sopa.clear(); dic.clear();
		scanf("%i %i %i\n", &d, &n, &m);
	}

	return 0;
}

