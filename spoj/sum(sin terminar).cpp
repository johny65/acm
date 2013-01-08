#include <iostream>
#include <vector>

#define big long long

using namespace std;

int cuenta = 0;

void sumfour(int n, vector<big> &v1, vector<big> &v2, vector<big> &v3, vector<big> &v4)
{
//	asm {
//		mov eax, 0
//		fori:
//			mox ebx, 0
//			forj:
//				mov ecx, 0
//				fork:
//					mov edx, 0
//					forl:
//						mov edi, v1[edx]
//						add edi, v2[edx]
//						cmp edi, 0
//						jne 
//						
//				
//	}
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			for (int k=0; k<n; ++k){
				for (int l=0; l<n; ++l){
					if (v1[i] + v2[j] + v3[k] + v4[l] == 0) cuenta++;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, n1, n2, n3, n4;
	cin>>n;
	vector<big> v1(n), v2(n), v3(n), v4(n);
	for (int i=0; i<n; ++i){
		cin>>n1>>n2>>n3>>n4;
		v1[i] = n1;
		v2[i] = n2;
		v3[i] = n3;
		v4[i] = n4;
	}
	sumfour(n, v1, v2, v3, v4);
	cout<<cuenta<<'\n';
	return 0;

}
