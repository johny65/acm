#include <iostream>
#include <set>
using namespace std;

#define V_HIGH 1000000000

multiset<int> a, b;

int main() {
    int N, i, RES, tmp;
    set<int>::iterator it1, it2;

    cin >> N;

    for (i=0; i<N; i++) { cin >> tmp; a.insert(tmp); }
    a.insert(V_HIGH+1);

    for (i=0; i<N; i++) { cin >> tmp; b.insert(tmp); }

    RES = 0;
    while (true) {
        it1 = a.begin();
        it2 = b.upper_bound(*it1);
        if (it2 == b.end()) break;
        a.erase(it1); b.erase(it2);
        RES++;
    }
    cout << RES << endl;

    return 0;
}
