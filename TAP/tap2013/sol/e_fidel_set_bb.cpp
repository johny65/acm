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
    int S, l, r, m, i;

    cin >> s; S = (int)s.size();
    assert(S_LOW <= S && S <= S_HIGH);
    l = 0; r = 21;
    while (r-l > 1) {
        m = (l+r)/2; sub.clear();
        for (i=0; i+m<=S; i++) sub.insert(s.substr(i, m));
        if ((int)sub.size() == (1<<m)) l = m;
        else r = m;
    }
    cout << l+1 << endl;

    return 0;
}
