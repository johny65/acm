#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class carta {
public:
	int c, s, t;
	carta(){};
	carta(int c1, int s1, int t1) : c(c1), s(s1), t(t1) {}
	bool operator <(const carta &c2) const {
		if (t > c2.t) return true;
		if (t == c2.t){
			if (c > c2.c) return true;
			if (s > c2.s) return true;
		}
		return false;
	}
};

void jugar(vector<carta> &mano, vector<carta> &mazo, int caso)
{
	int score=0, turnos=1;
	while (mano.size() > 0 && turnos > 0){
		if (mano.size() > 1) sort(mano.begin(), mano.end());
		//juego una carta
		if (mazo.size() == 0 && mano[0].t == 0){
			//si no quedan más cartas en el mazo, y no me van a dar más turnos, jugar la de más score
			int maxs = -1, indmax = -1;
			for (int i=0; i<mano.size(); ++i){
				if (mano[i].s > maxs){
					maxs = mano[i].s;
					indmax = i;
				}
			}
			score += mano[indmax].s;
			mano.erase(mano.begin()+indmax);
			turnos--;
			continue;
		}
		score += mano[0].s;
		turnos += mano[0].t;
		if (mano[0].c != 0){ //juntar cartas
			if (mano[0].c >= mazo.size() && mazo.size() != 0){
				//juntar todas
				//mano.insert(mano.end(), mazo.begin(), mazo.end());
				for (int i=0; i<mazo.size(); ++i)
					mano.push_back(carta(1,2,3));
				mazo.clear();
			}
			else if (mazo.size() != 0) {
				for (int i=0; i<mano[0].c; ++i){
					mano.push_back(mazo[i]);
					//mazo.erase(mazo.begin()+i);
				}
				//sacarlas del mazo
				mazo.erase(mazo.begin(), mazo.begin()+mano[0].c);
			}
		}
		//quitar la carta de mi mano
		mano.erase(mano.begin());
		turnos --;
	}
	cout<<"Case #"<<caso<<": "<<score<<'\n';
}
		
int main(){
	int T, n, m;
	cin>>T;
	int c, s, t;
	for (int i=0; i<T; ++i){
		cin>>n;
		vector<carta> mano;
		for (int j=0; j<n; ++j){
			cin>>c>>s>>t;
			carta nueva(c, s, t);
			mano.push_back(nueva);
		}
		cin>>m;
		vector<carta> mazo;
		for (int j=0; j<m; ++j){
			cin>>c>>s>>t;
			carta nueva(c, s, t);
			mazo.push_back(nueva);
		}
		jugar(mano, mazo, i+1);
	}
	return 0;
}
