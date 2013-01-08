#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Grande {
private:
	//guarda el número como un string, "123456789" es el número 987654321
	string digitos;
		
public:
	Grande() : digitos("") {}; //constructor vacío
	Grande(const Grande &g) : digitos(g.digitos) {}; //constructor de copia
	Grande(string numero){ //constructor general
		reverse(numero.begin(), numero.end());
		digitos = numero;
		for (int i=0; i<digitos.length(); ++i)
			digitos[i] -= '0';
	}
	bool impar(){ return digitos[0]%2; }
	bool par(){ return !impar(); }
	//asignación:
	Grande operator=(const Grande &g){
		digitos = g.digitos;
		return *this;
	}
	//suma:
	Grande operator+(const Grande &g){
		int carry=0, aux;
		Grande res;
		for (int i=0; i<res.digitos.length(); ++i){
			aux = carry + digitos[i] + g.digitos[i];
			res.digitos[i] = (char)aux % 10;
			carry = aux/10;
		}
		return res;
	}
	//menos 2
	Grande menos2(){
		
	}
	//división
	Grande div2(){
		int acarreo=0, tam=this->digitos.length()-1;
		Grande aux;
		for(int i=0; i<this->digitos.length(); i++){
			aux.digitos[i]=((10*acarreo)+digitos[tam])/2;
			acarreo=digitos[tam]%2;
			tam--;
		}
		reverse(aux.digitos.begin(), aux.digitos.end());
		return aux;	
	}
	
	
	void mostrar(){
		for (int i=digitos.length()-1; i>=0; --i)
			cout<<(int)digitos[i];
	}
};


int main()
{
	string n;
	cout<<"ingrese n"<<endl;
	
	getline(cin, n);
	if (n=="1"){ 
		cout<<1<<'\n';
		return 0;
	}
	Grande l=1, fk1(n), fl("0");
	while (fl!=1){
		//fl = (0.5 + 2.5 * (fk1 % 2)) * fk1 + (fk1 % 2);
		//se traduce como:
		//si fk1 es par, fl = fk1/2
		//si fk1 es impar, fl = 3*fk1 + 1;
		if (fk1.par())
		
		fk1=fl;
		l++;
	}
	cout<<"l= "<<l<<endl;
	return 0;
}

