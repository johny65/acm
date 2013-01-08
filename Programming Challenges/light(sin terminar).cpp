#include <iostream>

using namespace std;

void luces(unsigned long n)
{
	bool ultimaluz = false;
	
	unsigned long hasta = (unsigned long)(n/2)+1;
	for (unsigned long p=1; p<=hasta; p++){ //pasada
		if (n%p == 0)
			ultimaluz = !ultimaluz;
	}

	ultimaluz = !ultimaluz; //la pasada número n
	if (ultimaluz)
		cout<<"yes\n";
	else
		cout<<"no\n";
	
	return;
}

int main()
{
	unsigned long n;
	cin>>n;
	while (n != 0){
		luces(n);
		cin>>n;
	}
	return 0;
}
