#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> sol;


void masalto(map<string, vector<int> > &m)
{
	//primero de todo ver si todas las series son iguales
	//si lo son, no gana nadie
	map<string, vector<int> >::iterator q = m.begin(), p=q++;
	bool iguales = true;
	while (q != m.end()){
		if (p->second != q->second){
		    //ya hay 2 no iguales
		    iguales = false;
		    break;
		}
		p++; q++;
	}
	if (iguales){
		sol.push_back("-");
		return;
	}
	//----------------------------------------------------------------

/*	int masalto=0, susveces=0;
	while (q != m.end()){
		int alto=q->second[q->second.size()-1];
		int veces=1;
		for (int i=q->second.size()-2; i>=0; i--){
			if (q->second[i] == alto) veces++;
			else break;
		}
		if (alto>masalto){
			masalto=alto;
			susveces=veces;
			mq = q;
		}
		else if(alto == masalto){
			if (veces>susveces){
				masalto=alto;
				susveces=veces;
				mq = q;
			}
		}
		
				
		
		q++;
		
	}
}

*/
}
	
	
void factoresprimos(int p, vector<int> &v)
{
	while (p != 1){
		int desde=2;
		for (int i=desde; i<=p; i++){
			if(p%i == 0){
				v.push_back(i);
				desde=i;
				p/=i;
				break;
			}
		}
	}
}

	
void ahexa(int n, vector<int> &v)
{
	while (n != 0){
		int temp = n%16;
		v.insert(v.begin(), temp);
		n/=16;
	}
}


void calcular(map<string, vector<int> > &m, string nombre, int numero)
{
	//día
	int dia = numero%10;
	numero/=10;
	dia+=(numero%10)*10;
	numero/=10;

	//mes
	int mes = numero%10;
	numero/=10;
	mes+=(numero%10)*10;
	numero/=10;

	//anio
	int anio = numero;

	int p = dia*mes;
	vector<int> v;
	factoresprimos(p, v);
	ahexa(anio, v);
	sort(v.begin(), v.end());
	m[nombre] = v;
	
}

int main()
{
	/*vector<int> v;
	int n;
	while (true){
		cout<<"Ingrese valor: ";
		cin>>n;
		factoresprimos(n, v);
		for (unsigned int i=0; i<v.size(); i++)
		    cout<<v[i]<<'\n';
		v.clear();
	}
	*/
	
	int n;
	cin>>n;
	while (n != 0){
        map<string, vector<int> > datos;
		for (int i=0; i<n; i++){
			string t;
			int m;
			cin>>t>>m;
			calcular(datos, t, m);
		}
		masalto(datos);
		cin>>n;
	}
	
	//mostrar resultado
	for (unsigned int i=0; i<sol.size(); i++){
		cout<<"Caso "<<i+1<<":\n";
		if (sol[i] == "-")
		    cout<<"No va nadie, lalala!\n";
		else
		    cout<<"La ICPC entrega el ICPC para viajar al ICPC en el ICPC a "<<sol[i]<<" por tener un ICPC, calculado seg"<<char(163)<<"n la ICPC, superior al resto\n";
	}
	cout<<"ICPC resuelto";
	return 0;
}
