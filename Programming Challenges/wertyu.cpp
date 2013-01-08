#include <iostream>
#include <string>

using namespace std;

int main()
{
	string linea;
	while (getline(cin, linea)){
		string res = linea;
		for (unsigned int i=0; i<linea.length(); i++){
			switch (linea[i]){
				case '2':
					res[i] = '1';
					break;
				case '3':
					res[i] = '2';
					break;
				case '4':
					res[i] = '3';
					break;
				case '5':
					res[i] = '4';
					break;
				case '6':
					res[i] = '5';
					break;
				case '7':
					res[i] = '6';
					break;
				case '8':
					res[i] = '7';
					break;
				case '9':
					res[i] = '8';
					break;
				case '0':
					res[i] = '9';
					break;
				case '-':
					res[i] = '0';
					break;
				case '=':
					res[i] = '-';
					break;
				case 'W':
					res[i] = 'Q';
					break;
				case 'E':
					res[i] = 'W';
					break;
				case 'R':
					res[i] = 'E';
					break;
				case 'T':
					res[i] = 'R';
					break;
				case 'Y':
					res[i] = 'T';
					break;
				case 'U':
					res[i] = 'Y';
					break;
				case 'I':
					res[i] = 'U';
					break;
				case 'O':
					res[i] = 'I';
					break;
				case 'P':
					res[i] = 'O';
					break;
				case '[':
					res[i] = 'P';
					break;
				case ']':
					res[i] = '[';
					break;
				case '\\':
					res[i] = ']';
					break;
				case 'S':
					res[i] = 'A';
					break;
				case 'D':
					res[i] = 'S';
					break;
				case 'F':
					res[i] = 'D';
					break;
				case 'G':
					res[i] = 'F';
					break;
				case 'H':
					res[i] = 'G';
					break;
				case 'J':
					res[i] = 'H';
					break;
				case 'K':
					res[i] = 'J';
					break;
				case 'L':
					res[i] = 'K';
					break;
				case ';':
					res[i] = 'L';
					break;
				case 'X':
					res[i] = 'Z';
					break;
				case 'C':
					res[i] = 'X';
					break;
				case 'V':
					res[i] = 'C';
					break;
				case 'B':
					res[i] = 'V';
					break;
				case 'N':
					res[i] = 'B';
					break;
				case 'M':
					res[i] = 'N';
					break;
				case ',':
					res[i] = 'M';
					break;
				case '.':
					res[i] = ',';
					break;
				case '/':
					res[i] = '.';
					break;
				case '\'':
					res[i] = ';';
					break;
				
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
