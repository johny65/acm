#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

struct a {
	int h, m, s;
	char c;
	bool operator<(const a &b) const {
		if (h != b.h) return (h<b.h);
		if (m != b.m) return (m<b.m);
		if (s != b.s) return (s<b.s);
	}

};

int main()
{
	int n;
	cin>>n; cin.ignore();
	int h, m, s;
	char c;
	while (n != 0){
		vector<a> v(n);
		int cant_E=0,cant_X=0;
		for (int i=0; i<n; i++){
			a aa;
			scanf("%d:%d:%d %c\n", &h, &m, &s, &c);
			//cout<<h<<" "<<m<<" "<<s<<" "<<c<<'\n';
			aa.h = h;
			aa.m = m;
			aa.s = s;
			aa.c = c;
			if(c=='E') cant_E++; else cant_X ++;
			v[i] = aa;
		}
		sort(v.begin(), v.end());
		
		//
		//for (int i=0; i<v.size(); i++)
			//cout<<v[i].h<<" "<<v[i].m<<" "<<v[i].s<<" "<<v[i].c<<'\n';
		//
				
		int adentro = 0,adentro_max=0;
		for (int i=0; i<n; i++){
			if(adentro>adentro_max){adentro_max=adentro;/*cout<<endl<<"adentro_max  "<<adentro_max<<endl;*/}
			switch (v[i].c){
				case 'E':
					adentro++;
					cant_E--;
					//cout<<"adentro "<<adentro<<endl;
					break;
				case 'X':
					adentro--;
					cant_X--;
					break;
				case '?':
					cant_X--;
					if (!adentro){
						adentro++;
						break;
					}
					if (cant_E-cant_X+adentro == -1)
						adentro++;
					else adentro--;
			} //del primer switch
		} //del for i
		cout<<adentro_max<<'\n';
		cin>>n; cin.ignore();
	}
	return 0;
}
