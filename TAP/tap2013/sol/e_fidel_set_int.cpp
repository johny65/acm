#include <iostream>
#include <string>
#include <set>
#include <cassert>
using namespace std;

#define S_LOW 1
#define S_HIGH 100000

string s;
set<int> sub;

int main() {
    int S, i, j, k, tmp;

    cin >> s; S = (int)s.size();
    assert(S_LOW <= S && S <= S_HIGH);
    for (i=1; ; i++) {
        sub.clear();
        for (j=0; j+i<=S; j++) {
            tmp = 0;
            for (k=j; k<j+i; k++) tmp = tmp*2 + s[k]-'0';
            sub.insert(tmp);
        }
        if ((int)sub.size() < (1<<i)) break;
    }
    cout << i << endl;

    return 0;
}
