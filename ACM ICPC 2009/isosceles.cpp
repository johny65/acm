#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define EPS 1e-12

using namespace std;

void triangulos(vector< pair<double, double> > &v)
{
	int cant=0;
	
	for (int i=0; i<v.size(); i++){
		for (int j=i+1; j<v.size(); j++){
			double l1 = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
			//double l1 = (v[i].first -v[j].first)*(v[i].first -v[j].first) +
				//			(v[i].second -v[j].second)*(v[i].second -v[j].second);
							
			for (int k=j+1; k<v.size(); k++){
				double l2 = abs(v[i].first - v[k].first) + abs(v[i].second - v[k].second);
				//double l2 = (v[i].first -v[k].first)*(v[i].first -v[k].first) +
				//			(v[i].second -v[k].second)*(v[i].second -v[k].second);
				if(abs(l1-l2) < EPS) {cant++; continue;}
				//double l3 = (v[j].first -v[k].first)*(v[j].first -v[k].first) +
					//		(v[j].second -v[k].second)*(v[j].second -v[k].second);
				double l3 = abs(v[j].first - v[k].first) + abs(v[j].second - v[k].second);
				
				if (abs(l2-l3) < EPS || abs(l1-l3) < EPS) cant++;
			}
		}
	}
	
	cout<<cant<<'\n';
	return;
}


int main()
{
	int n, x, y;
	scanf("%d\n", &n);
	while (n != 0){
		vector< pair<double, double> > v;
		for (int i=0; i<n; i++){
			scanf("%d %d\n", &x, &y);
			v.push_back(pair<double, double>(x, y));
		}
		triangulos(v);
		scanf("%d\n", &n);
	}
	return 0;
}
