#include <iostream>
#include <string>
#include <set>
#include <cassert>
using namespace std;

#define S_LOW 1
#define S_HIGH 100000

string s;
set<string> sub;

int main() {
    int S, i, j;

    cin >> s; S = (int)s.size();
    assert(S_LOW <= S && S <= S_HIGH);
    for (i=0; i<S; i++) assert(s[i] == '0' || s[i] == '1');
    for (i=1; ; i++) {
        sub.clear();
        for (j=0; j+i<=S; j++) sub.insert(s.substr(j,i));
        if ((int)sub.size() < (1<<i)) break;
    }
    cout << i << endl;

    return 0;
}
