#include <iostream>
#include <string>
#include <vector>

using namespace std;

void lcd(int s, int n)
{
	vector<int> nums;
	

int main()
{
	int s, n;
	scanf("%d %d", &s, &n);
	while (s != 0 && n != 0){
		lcd(s, n);
		scanf("%d %d", &s, &n);
	}
	return 0;
}
