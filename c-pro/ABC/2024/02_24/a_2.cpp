#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> P(N+1);
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        P[p] = i;
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        if (P[a] < P[b]) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }

    return 0;
}