#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector< set<int> > res;

void calcular(vector<int> &v, int max)
{
	set<int> p, s;
	int tam = v.size();
	int m=tam+1, pm=m, mv;
	int i=0; //índice
	int sum=0;
	//revisar cada número posible
	int n=1;
	while (n <= max){
		int vi = v[i];
		if (vi > n || i==tam){
			if (sum<m){
				mv = n;
				m=sum;
				p.clear();
			}
			else if (sum==m){
				p.insert(n);
				pm=sum;
			}
			sum=0;
			n++;
		}
		else if (vi == n){
			sum++;
			i++;
		}
	}
	if (m == pm){
		s = p;
	}
	s.insert(mv);	
	res.push_back(s);
}

int main()
{
	int n, c, k;
	cin>>n>>c>>k;
	while (n != 0){
		vector<int> nums;
		int t;
		for (int i=0; i<n; i++){
			for (int j=0; j<c; j++){
				cin>>t;
				nums.push_back(t);
			}
		}
		sort(nums.begin(), nums.end());
		calcular(nums, k);
		cin>>n>>c>>k;
	}
	
	//mostrar
	for (unsigned int i=0; i<res.size(); i++){
		set<int>::iterator q = res[i].begin();
		cout<<*q;
		q++;
		while (q != res[i].end()){
			cout<<' '<<*q;
			q++;
		}
		cout<<'\n';
	}
	return 0;
}
