#include <iostream>
#include <map>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> par;
//typedef <par>::iterator iter;
typedef map<ull, ull> mapa;
typedef mapa::iterator iter;

/*
bool comp(const par &p1, const par &p2)
{
	return (p1.first < p2.first);
}
*/

mapa potencias;

ull power(ull b, ull expon, ull p)
{
	if (expon == 0) return 1;
	if (expon == 1) return b;
	iter it = potencias.lower_bound(expon);
	if( it->first == expon ) return it->second;
	
	ull aux = power(b, expon/2, p) % p;
	aux = (aux*aux) % p;
	if (expon%2)
		aux = (aux*b)%p;
	potencias.insert( it, make_pair(expon, aux) );
	return aux;
}
	

void hash(mapa &v, ull i, ull j, ull b, ull p)
{
	ull h = 0;
	//for (ull k=0; k <= j-i; ++k){
		//cout<<"k: "<<k<<" - b a la: "<<k<<"  f : "<<j-k<<endl;
	//for (iter it = lower_bound(v.begin(), v.end(), make_pair(i, 0), comp); it != v.end() && it->first <= j; it++){
	for (iter it = v.lower_bound(i); it != v.end() && it->first <= j; it++){
		//cout<<"s";
		ull aux = power(b, j-it->first, p);
		/*
		if (k%2){ //impar
			aux = ((aux % p) * (aux % p)) % p;
			aux = ((aux % p) * (b % p)) % p;
		}
		else {
			aux = ((aux % p) * (aux % p)) % p;
		}
		*/
		h += ((aux % p) * (it->second % p)) % p;
		h = h%p;
		//cout<<"-------------h: "<<h<<endl;
	}
	cout<<h<<endl;
}
	



int main(){

	ios::sync_with_stdio(false);
	
	ull b, p, n, l;
	while (cin>>b>>p>>l>>n && b != 0 && p != 0 && l != 0 && n != 0){
		//cout<<p<<endl;
		//vector<ull> v(l+1);
		//list<par> v;
		b %= p;
		mapa v;
		//potencias.clear();
		for (int i=0; i<n; ++i){
			char c;
			ull i, val;
			cin>>c>>i>>val;
			if (c == 'E'){
				//v[i] = val;
				//par p = make_pair(i, val);
				//iter it = v.lower_bound(v.begin(), v.end(), make_pair(i,0), comp);
				iter it = v.lower_bound(i);
				
				if (it != v.end()){
					//cerr<<it->first<<" "<<it->second<<" i: "<<i<<endl;
					//par pp = *it;
					if (i == it->first) it->second = val;
					else {
						v.insert(it, make_pair(i, val));
					}
				}
				else {
					v.insert(it, make_pair(i, val));
				}
				
			}
			else if (c == 'H'){
				hash(v, i, val, b, p);
			}
		}
		cout<<"-\n";
	}
	return 0;
	
}

				
