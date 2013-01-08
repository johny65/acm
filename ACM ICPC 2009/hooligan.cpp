#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*
int main()
{
	int n, m, g;
	scanf("%d %d %d\n", &n, &m, &g);
	
	int e1, e2;
	char c;
	pair<int, int> blanco(0, 0);

	while (!(n == 0 && m == 0 && g == 0)){
		vector< pair<int, int> > equipos(n, blanco);
		for (int i=0; i<g; i++){
			cin>>e1>>c>>e2;
			cin.ignore();
			cout<<e1<<" "<<e2<<" "<<equipos.size()<<' '<<c<<'\n';
			switch (c){
				case '=':
					equipos[e1].first++;
					equipos[e2].first++;
					break;
				case '<':
					equipos[e2].first+=2;
					break;
				case '>':
					equipos[e1].first+=2;
					break;
			}
			//números de partidos
			equipos[e1].second++;
			equipos[e2].second++;
		}
		
		//hacer(equipos);
		
		scanf("%d %d %d\n", &n, &m, &g);
	}
	
	return 0;
}
*/


int main()
{
	int n, m, g;
	scanf("%d %d %d\n", &n, &m, &g);
	
	int e1, e2;
	char c;
	
	while (!(n == 0 && m == 0 && g == 0)){
		
		//matriz
		vector<int> blanco(n, -1);
		vector< vector<int> > v(n);
		for (int i=0; i<v.size(); i++)
			v[i] = blanco;
		
		
