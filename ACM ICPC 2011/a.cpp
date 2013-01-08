#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

struct nodo{
	nodo(){}
	nodo(int inic, int fin):inic(inic), fin(fin){}
	int inic, fin;
	bool operator<(const nodo &b) const{
		return inic<b.inic;
	}
};

typedef pair<int, int> iint;
typedef vector<nodo> lista;
typedef lista::iterator iter;

lista v;

iter buscarl(int n){
	if(n < v.begin()->inic) return v.end(); 
	//return lower_bound( v.begin(), v.end(), nodo(n,n) );
	for(iter K=v.begin(); K!=v.end(); ++K){
		//cerr << "nodo " << K->inic << ' ' << K->fin << endl;
		if(K->inic <= n and K->fin >= n)
			return K;
		if(n < K->inic) return K-1; 
	}
	return v.end();
}

iter buscarr(int n){
	if(n < v.begin()->inic) return v.begin(); 
	//return lower_bound( v.begin(), v.end(), nodo(n,n) );
	for(iter K=v.begin(); K!=v.end(); ++K){
		//cerr << "nodo " << K->inic << ' ' << K->fin << endl;
		if(K->inic <= n and K->fin >= n)
			return K;
		if(n < K->inic) return K; 
	}
	return v.end();
}



iint survivors(int inic, int fin){
	if(v.empty()) return make_pair(-1,-1);
	//buscar el nodo donde se produjo el disparo
	iter left = buscarl(inic), rigth = buscarr(fin);
	//if(left == v.end() and rigth == v.end()) return make_pair(-1,-1);


	//actualizar la estructura
	if(left == rigth){ //solo un  nodo afectado. 
		//muerte 
		if(left->inic == inic and left->fin==fin){
			left = v.erase(left);
			return make_pair( (left-1)->fin, (left)->inic );
		}
		else if(left->inic == inic){
			left->inic = fin+1;
			return make_pair( (left-1)->fin, (left)->inic );
		}
		else if(left->fin == fin){
			left->fin = inic-1;
			return make_pair( left->fin, (left+1)->inic );
		}
		//Mitosis
		else{
		//	cerr << "mitosis" << endl;
			int aux = left->fin;
			left->fin = inic-1;
			v.insert(left+1, nodo(fin+1,aux));
			//left->fin = inic-1;
			return make_pair( inic-1, fin+1 );
		}
	}
	else{
		rigth = v.erase(left+1, rigth); //todos murieron T_T
	
		rigth->inic = fin+1;
		left->fin = inic-1;
		
	}
	//devolver el par izq-der interesante
	return make_pair(inic-1, fin+1);
}

void analisis(int n, int maxi){
	if(n<=0 or n>maxi) cout << '*';
	else cout << n;
}


int main(){
	size_t soldados, bajas;
	while(cin>>soldados>>bajas and not (soldados==0 and bajas==0) ){
		v.clear();
		v.push_back( nodo(-1,-1) );
		v.push_back( nodo(1,soldados) );
		v.push_back( nodo(soldados+1,soldados+1) );
		//cerr << v[0].inic << ' ' << v[0].fin << endl;
		for(size_t K=0; K<bajas; K++){
			int inic, fin;
			cin>>inic>>fin;
			iint p = survivors(inic, fin);
			analisis(p.first, soldados); cout << ' ';
			analisis(p.second, soldados); cout << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}
