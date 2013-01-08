#include <iostream>
#include <vector>

using namespace std;


//void conv(vector<int> &v)
//{
//	int lo = v.size();
//	int t =lo + 2*(lo-1);
//	int t2 = 2*lo-1;
//	vector<int> c(t2,0);
//	
//	vector<int> aux;
//	
//	//meter 0 al principio
//	for (int i=0; i<lo-1; i++)
//		aux.push_back(0);
//	for (int i=0; i<lo; i++)
//		aux.push_back(v[i]);
//	for (int i=0; i<lo-1; i++)
//		aux.push_back(0);
//	
//	
//	for (int i=0; i<t2; i++){
//		for (int k=0; k<lo; k++){
//			c[i] += aux[i+k]*v[lo-1-k];
//		}
//	}
//	for(int i=0;i<t2;i++)
//		cout<<c[i]<<" ";
//	
//}



int factorial(int n)
{
	if (n == 0 || n==1) return 1;
	return n*factorial(n-1);
	
}
void calcular(vector<int> &v, int n)
{
	int suma=1;
	for (int i=0; i<v.size(); i++){
		if (v[i]==0) continue;
		suma *= factorial(v[i]);
	}
	cout<<factorial(n) / suma<<'\n';
}


int main(int argc, char *argv[]) {
	
	int n, k;
	int temp;
	while (cin>>n>>k){
		vector<int> v;
		for (int i=0; i<k; i++){
			cin>>temp;
			v.push_back(temp);
		}
		calcular(v, n);
	}

	return 0;
}

