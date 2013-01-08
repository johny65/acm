
#include <iostream>
#include <map>
#include <list>

#include <utility>
#include <string>
#include <queue>
using namespace std;
#define FOR(n,i)	for(int i=0;i<n;i++)
#define present(cont,elem)	( cont.find(elem) != cont.end() )
#define tr(cont, it)	for(typeof( cont.begin()) it=cont.begin(); it != cont.end(); it++) 

int profundidad(map<string,string> &arbol,string persona){
	int prof=0;
	while(arbol[persona]!=persona) {//llegue a raiz
		persona=arbol[persona]; //subo un nivel
		prof++;
	}
	return prof;
}

void busq_ancho(map<string,list<string> > &grafo,map<string,string> &arbol,string raiz){
	arbol[raiz]=raiz; //es raíz si se apunta a sí mismo
	queue<string> hijo;//cola de vertices a procesar
	hijo.push(raiz);
	while(!hijo.empty()){
		raiz=hijo.front();
		while(!grafo[raiz].empty()){
			string aux=	grafo[raiz].back();
			grafo[raiz].pop_back();
			if(!present(arbol,aux)){
				arbol[aux]=raiz; //apuntan al padre
				hijo.push(aux); //agrega los hijos a la cola
			}
		}
		hijo.pop();
	}
}

int main(int argc, char *argv[]) {
	int casos,papers,doctors;
	string trabajo,persona;
	map<string,list<string> > grafo;
	map<string,string> arbol;
	list<pair<string,int> > number;
	cin>>casos;
	FOR(casos,i){
		number.clear();grafo.clear();arbol.clear();
		cin>>papers>>doctors;
		cin.ignore();
		FOR(papers,j){
//			cin>>trabajo;
			getline(cin,trabajo);
			
//			cout<<trabajo;
			//separación de los doctores
			int b;string aux;list<string> conex;
			trabajo.erase(trabajo.find(":"));
			while( (b=trabajo.find(".,")) <= trabajo.size()){
				aux=trabajo.substr(0,b+1); //aux tiene el nombre de los doctos
				trabajo.erase(0,b+3);
				conex.push_back(aux);	//conex tiene a los doctores del paper
			}
			conex.push_back(trabajo);
			
			//creación del grafo
			tr(conex,it){
				tr(conex,jt){
					if(*it!=*jt) //para no hacer lazos
						grafo[*it].push_back(*jt);
				}
			}
//			tr(grafo,it){
//				cout<<it->first<<endl;
//			}
		}
		//creacion del arbol Erdos
		//busqueda a lo ancho
		if(present(grafo,"Erdos, P."))
			busq_ancho(grafo,arbol,"Erdos, P.");
		//salida
//		cout<<endl<<"arbol "<<arbol.size()<<endl;
		cout<<"Scenario "<<i+1<<endl;
		FOR(doctors,j){
			getline(cin,persona);
			cout<<persona<<' ';
			if(present(arbol,persona))
				cout<<profundidad(arbol,persona);
			else
				cout<<"infinity";
			cout<<endl;
		}
	}
//	cin>>persona;
	return 0;
}
