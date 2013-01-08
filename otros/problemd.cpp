#include <string>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

int main()
{
	vector<int> sol;	
	string f, n;
	cout<<"Ingrese datos:\n";
	cin>>f>>n;
	while (f != "0" && n!="0")
	{
		int j=2;
		int nn = atoi(n.c_str());
		int ns = nn;
		stringstream temp;
		temp<<ns;
		string nss = temp.str();
		bool salir=false;
		while (true){
			for (int i=0; i<nss.length(); i++){
				if (f.find(nss[i]) == string::npos){ break;}
				if (i==nss.length()-1){
 					sol.push_back(ns);
					salir = true;
				}
			}
			ns = nn*j;
			stringstream temp; temp<<ns; nss = temp.str();
			j++;
			if (j==99){
				sol.push_back(-1);
				break;		
			}
			if (salir){
				salir = !salir;
				break;
			}
		}
		cout<<"Ingrese datos:\n";
		cin>>f>>n;
	}
	
	for (int i=0; i<sol.size(); i++){
		if (sol[i]==-1)	
			cout<<"impossible"<<'\n';
		else
			cout<<sol[i]<<'\n';
	}
	return 0;
}
