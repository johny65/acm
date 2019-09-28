#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int m,n;

int borrar(int **mat, int i, int j,vector<int> &v){
	v[i-1]=v[i+1]=0; 
	v[i]-=(mat[i][j-1] + mat[i][j] + mat[i][j+1]);
	mat[i][j] = 0;
	int s=1;
	for(int c=1;c<=n;c++){
		if (mat[i-1][c]){
			s++;
			mat[i-1][c] = 0;
		}
		if (mat[i+1][c]){
			s++;
			mat[i+1][c] = 0;
		}
	}
	if (mat[i][j-1]){
		s++;
		mat[i][j-1] = 0;
	}
	if (mat[i][j+1]){
		s++;
		mat[i][j+1] = 0;
	}
	return s;
}

int magia(int** mat, vector<int> &v){
   int d=0;
   int x, y;
   int borrados=0,m_n=m*n,per;
   while(borrados<m_n){
	   int minimo=INT_MAX;
	   for(int i=1;i<=m;i++){
		   for(int j=1;j<=n;j++){
			   if(!mat[i][j])continue;
			   per= v[i-1] + v[i+1] + mat[i][j-1] + mat[i][j+1];
			   if(per<minimo){
				   minimo=per;
				   x=i;
				   y=j;
			   }
		   }
	   }
	   d+=mat[x][y];
	   borrados+=borrar(mat,x,y,v);
   }
   return d;
}


int main(int argc, char *argv[]) {
	int r;
	cin>>m>>n;
	
	while(m!=0 || n!=0){
		int **mat=new int*[m+2];
		vector<int> v(m+2,0);
		for(int i=0;i<=m+1;i++){
			mat[i]=new int[n+2];
			if(i==0 || i==m+1) continue;
			mat[i][0]=0;
			mat[i][n+1]=0;
			for(int j=1;j<=n;j++){
				cin>>mat[i][j];
			    v[i]+=mat[i][j];
			}
		}
		for(int j=0;j<n+2;j++){
			mat[0][j]=0;
			mat[m+1][j]=0;
		}
		r = magia(mat,v);
		cout<<r<<'\n';
		cin>>m>>n;
	}
	return 0;
}
