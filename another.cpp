//resuelto!!
//http://acm.uva.es/problemset/
//Your C++ program has solved Ok the problem 4472 (Another Crisis)
//in 0.480 seconds using as much as 3504 kbytes of virtual memory.
//Congratulations!

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class nodo {
public:
	bool worker;
	int workers;
	vector<nodo*> hijos;
	nodo *papa;
	nodo() : worker(true), workers(0) {};
};

int minimonodo(nodo *nn, int t)
{
	
	int minimo=0;
	
	int necesarios = ceil(nn->hijos.size() * t / 100.0);
	if (nn->workers >= necesarios)
		return necesarios;
	
	int bossnecesarios = necesarios - nn->workers;
	
	vector<int> auxes;
	
	for (int i=0; i<nn->hijos.size(); i++){
		if (nn->hijos[i]->worker) continue;
		int temp = minimonodo(nn->hijos[i], t);
		auxes.push_back(temp);
	}
	
	sort(auxes.begin(), auxes.end());

	for (int i=0; i<bossnecesarios; i++){
		minimo+=auxes[i];
	}
	
	minimo += nn->workers;
	return minimo;
}


int main()
{
	int n, t;
	cin>>n>>t;
	int temp;
	while (n != 0 && t != 0){
		vector<nodo> arbol(n+1);
		for (int i=1; i<=n; i++){
			cin>>temp;
			arbol[temp].hijos.push_back(&(arbol[i]));
			arbol[i].papa = &arbol[temp];
			if (temp != 0 && arbol[temp].worker)
				arbol[temp].papa->workers--;
			if (arbol[i].worker)
				arbol[temp].workers++;
			arbol[temp].worker = false;

		}
		int res = minimonodo(&arbol[0], t);
		cout<<res<<'\n';
		
		//nuevo caso
		cin>>n>>t;
	}
	
	
	return 0;
}

