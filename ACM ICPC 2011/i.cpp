#include <iostream>
#include <string>
#include <sstream>
#include <vector>
 
using namespace std;


void adecimal(const vector<string> &v, int d)
{
	stringstream ss;
	int i=0;
	//while (i < v[0].length()){
	for (int j=0; j<d; ++j){
		string num = v[0].substr(i, 2);
		num += v[1].substr(i, 2);
		num += v[2].substr(i, 2);
		//cout<<num<<"_"<<num.length()<<endl;
		
		if (num == ".***..") ss<<0;
		else if (num == "*.....") ss<<1;
		else if (num == "*.*...") ss<<2;
		else if (num == "**....") ss<<3;
		else if (num == "**.*..") ss<<4;
		else if (num == "*..*..") ss<<5;
		else if (num == "***...") ss<<6;
		else if (num == "****..") ss<<7;
		else if (num == "*.**..") ss<<8;
		else if (num == ".**...") ss<<9;
		
		i += 3;
	}
	cout<<ss.str()<<endl;
	return;
}

string abraile(char c, int l)
{
	string s = "";
	switch (l){
		case 1: //linea 1
			switch (c) {
				case '0': 
				case '9':
					s += ".*";
					break;
				case '1':
				case '2':
				case '5':
				case '8':
					s += "*.";
					break;
				case '3':
				case '4':
				case '6':
				case '7':
					s += "**";
					break;
			}
			break;
			
		case 2: //línea 2
			switch (c) {
				case '0':
				case '7':
				case '8':
					s += "**";
					break;
				case '1':
				case '3':
					s += "..";
					break;
				case '2':
				case '9':
				case '6':
					s += "*.";
					break;
				case '4':
				case '5':
					s += ".*";
					break;
				
			}
			break;
		
		case 3: //linea 3:
			
			s += "..";
			break;
	}

	return s;
}

int main(){
	
	int d;
	char s;
	while (cin>>d && d != 0){
		string s2;
		cin>>s;
		if (s == 'S'){
			cin>>s2;
			string bra = "";
			for (int j=1; j<=3; ++j){
				for (int i=0; i<s2.length()-1; ++i){
					bra += abraile(s2[i], j);
					bra += " ";
				}
				cerr<<s2[s2.length()-1]<<"     "<<abraile(s2[s2.length()-1], j)<<endl;
				bra += abraile(s2[s2.length()-1], j);
				bra += "\n";
			}
			cout<<bra;
		}
		else if (s == 'B'){
			cin.ignore();
			vector<string> v(3);
			for (int i=0; i<v.size(); ++i){
				getline(cin, v[i]);
				//cout<<"linea: "<<s2<<endl;
				//if (s2[s2.length()-1] == '\n')
				//	cout<<"enter! \n";
			}
			adecimal(v, d);
		}
			
	}
	return 0;
	
}

