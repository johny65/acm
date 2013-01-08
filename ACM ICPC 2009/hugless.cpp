#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void magia3(vector<vector<int> > &v, int n, int mach){
	for(int i=1;i<n;i++){
		if(v[i][0]==-1){
	       	v[i][0] = mach*2;	
			v[0][i] = 0;
		}else{
		    if(v[i][0]+v[0][i]<mach*2){
				v[i][0]+=(mach*2)-v[i][0];
				v[0][i]+= 0;
			}	
		
		}
	}
	
}
	
void magia2(vector<int> &sump ,vector<vector<int> > &v,int j, int n){
	for(int i=0;i<n;i++){
		if(v[i][j]!=-1)
	       sump[j]+=v[i][j];	
	}
	
}

void magia4(int faltap ,vector<vector<int> > &v,vector<int> &sump, int n){
	int myp = sump[0]; 
	vector<int> ::iterator p1, p2;
	p1 = sump.begin();
	p1++;
	p2 = sump.end();
	p2--;
	  
	sort(p1, p2);
	/*for(int i=0;i<n;i++){
		cout<< sump[i]<<endl;
		}*/
	for(int i=n-1;i>0;i--){
	   if(myp<= sump[i]){
	    cout<<"N\n";
		return;
	   }
	   int aux = myp - sump[i]-1;
	   faltap-= aux;	
	}
	
	if(faltap<=0){
		cout<<"Y\n";
	}else{
		cout<<"N\n";
	}
}

void magia(vector<vector<int> > &v,int n, int m, int g){
	int totalp = n*(n-1)*m;
	int faltap = 0 ;
	int s=0;
	vector<int>  sump(n,0);
	magia3(v,n,m);
	for(int j=0;j<n;j++)
	   magia2(sump,v,j,n);
	for(int j=0;j<n;j++)
	    s+=sump[j];
	faltap = totalp - s;
	
	magia4(faltap,v, sump, n);
	

}

int main(){
 
   int j1, j2, n, m, g;
   char r;
   cin>>n>>m>>g;
   while(n!=0 && m!=0 && g!=0){
   vector<vector<int> > v(n);
   vector<int> vacio(n, -1);
 
   for(int i=0;i<n;i++)
      v[i]= vacio;
   for(int j=0;j<g;j++){
	   cin>>j1>>r>>j2;
	  // if(j1>j2) sw
	   switch(r){
	    case '<' :  if(v[j2][j1]==-1){
			           v[j2][j1]=0;
					   v[j1][j2]=0;
					}   
		             v[j2][j1]+= 0 ;
					 v[j1][j2]+= 2; 
					 break;	   
		case '>' :  if(v[j2][j1]==-1){
			           v[j2][j1]=0;
					   v[j1][j2]=0;
					} 
		            v[j2][j1]+= 2 ;
					v[j1][j2]+=0; 
					break;
					
		case '=' :  if(v[j2][j1]==-1){
			           v[j2][j1]=0;
					   v[j1][j2]=0;
					} 
		             v[j2][j1]+= 1 ; 
					 v[j1][j2]+= 1; 
					 break;
	   
	   }   	   
   
   }
   
   magia(v,n,m,g);
   v.clear();
   cin>>n>>m>>g;
 }
}
