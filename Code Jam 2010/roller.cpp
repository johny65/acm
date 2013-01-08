#include <iostream>
#include <deque>

using namespace std;

int calcular(deque<int> &cola, int r, int k, int n)
{
	if (cola.empty()) return 0;
	deque<int> cola2;
	int pesos = 0;
	int subidos = 0;
	int quedan = cola.size();
	for (int i=0; i<r; i++){
		while (true) {
			if (quedan == 0){
				break;
			}
			if (subidos + cola.front() > k)
				break;
			subidos += cola.front();
			cola.push_back(cola.front());
			cola.pop_front();
			quedan--;
		}
		pesos += subidos;
		subidos = 0;
		
		//reacomodar cola
		quedan = cola.size();
	}
	
	return pesos;
}


int main()
{
	deque<int> cola;
	int t; //casos
	int r, k, n;
	int g;
	cin>>t;
	for (int j=0; j<t; j++){
		cin>>r>>k>>n;
		for (int i=0; i<n; i++){
			cin>>g;
			cola.push_back(g);
		}
		cout<<"Case #"<<j+1<<": "<<calcular(cola, r, k, n)<<'\n';
		cola.clear();
	}
	
	return 0;
	
}
