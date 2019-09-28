#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> espiral(int buscado, pair<int, int> coor)
{
	int f = coor.first, c = coor.second;
	int subir=1, val=1;
	while (true){
		if (val == buscado) return pair<int, int>(f, c);
		//subo
		for (int i= 0; i<subir; i++){
			f = f-1;
			val++;
			if (val == buscado) return pair<int, int>(f, c);
		}
		//a la izquierda
		for (int i= 0; i<subir; i++){
			c = c-1;
			val++;
			if (val == buscado) return pair<int, int>(f, c);
		}
		//abajo
		for (int i= 0; i<subir+1; i++){
			f = f+1;
			val++;
			if (val == buscado) return pair<int, int>(f, c);
		}
		//derecha
		for (int i= 0; i<subir; i++){
			c = c+1;
			val++;
			if (val == buscado) return pair<int, int>(f, c);
		}
		c++; val++; subir+=2;
	}
}

int main()
{
	vector< pair<int, int> > res;
	int sz, p, i=0;
	cin>>sz>>p;
	while (sz != 0 && p != 0){
		pair<int, int> c((sz-1)/2, (sz-1)/2);
		pair<int, int> r = espiral(p, c);
		r.first = sz - r.first;
		r.second = r.second +1;
		res.push_back(r);
		i++;
		cin>>sz>>p;
	}
	for (unsigned int j = 0; j<res.size(); j++)
		cout<<"Line = "<<res[j].first<<", column = "<<res[j].second<<'\n';
	return 0;
}
