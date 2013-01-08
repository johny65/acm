#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int a, b;
	char op[4];
	cin>>a>>op>>b;
	while (true){
		if (!strcmp(op, "ADD")) //sumar
			cout<<a+b<<'\n';
		else if (!strcmp(op, "SUB")) //resta
			cout<<a-b<<'\n';
		else if (!strcmp(op, "MUL")) //multiplicar
			cout<<a*b<<'\n';
		else if (!strcmp(op, "DIV")){
			if (b==0) break;
			//dividir
			cout<<a/b<<'\n';
		}
		cin>>a>>op>>b;
	}
	return 0;
	
}

