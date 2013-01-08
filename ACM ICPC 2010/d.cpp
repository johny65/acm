#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void magia1(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=1;
}

}



void magia2(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=10;
	magia1(9,v,0);
}
}


void magia3(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=100;
	magia2(9,v,0);
}
}


void magia4(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=1000;
	magia3(9,v,0);
}
}

void magia5(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=10000;
	magia4(9,v,0);
}
}

void magia6(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=100000;
	magia5(9,v,0);
}
}

void magia7(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=1000000;
	magia6(9,v,0);
}
}

void magia8(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=10000000;
	magia7(9,v,0);
}
}

void magia9(int n, vector<int> &v, int ini ){

for(int i=ini;i<= n;i++){
	v[i]+=100000000;
	magia8(9,v,0);
}
}

int cifra(int num, int c){
	if(c!=1){
	num/= (c-1)*10;	
	}
	return num%10;
	}

void func(vector<int> & v, int num){
	stringstream ss;
	ss<<num;
	int cant = ss.str().length();
	
	
	switch (cant){
	
	case 1 : {magia1(cifra(num,1),v,1); break;}
	case 2 : {magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 3 : {magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 4 : {magia4(cifra(num,4),v,1); magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 5 : {magia5(cifra(num,5),v,1); magia4(cifra(num,4),v,1); magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 6 : {magia6(cifra(num,6),v,1); magia5(cifra(num,5),v,1); magia4(cifra(num,4),v,1); magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 7 : {magia7(cifra(num,7),v,1); magia6(cifra(num,6),v,1); magia5(cifra(num,5),v,1); magia4(cifra(num,4),v,1); magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 8 : {magia8(cifra(num,8),v,1); magia7(cifra(num,7),v,1); magia6(cifra(num,6),v,1); magia5(cifra(num,5),v,1); magia4(cifra(num,4),v,1); magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	case 9 : {magia9(cifra(num,9),v,1); magia8(cifra(num,8),v,1); magia7(cifra(num,7),v,1); magia6(cifra(num,6),v,1); magia5(cifra(num,5),v,1); magia4(cifra(num,4),v,1); magia3(cifra(num,3),v,1);magia2(cifra(num,2),v,1);magia1(cifra(num,1),v,1); break;}
	
	}	
		
}


void resta(vector<int> & v2,vector<int> & v1,vector<int> & v){
		for(int i=0;i<10;i++){
		v[i] = fabs(v2[i]-v1[i]);	
		}
}


void mostrar(vector<int> & v){
		for(int i=0;i<10;i++){
		cout<<v[i]<<" ";
		}
		cout << endl;
}


int main(){
	int a,b;
	cin>>a>>b;
	while(a!=0 && b!=0){
		/*
			vector<int> v1(10,0);
			vector<int> v2(10,0);
			vector<int> v(10,0);
			func(v1,a-1);
			func(v2,b);
			
			
			resta(v2,v1,v);*/
			vector<int> v(10,0);
			v.clear();
			func(v,12);
			mostrar(v);
			cin>>a>>b;
	}
	
	return 0;}
