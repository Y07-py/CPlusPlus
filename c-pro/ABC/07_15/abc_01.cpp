#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P, Q; cin >>  N >> P >> Q;
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    int total = 10000009;
    int temp = Q;
    for (int i = 0; i < N; i++) {
        temp += D[i];
        total = min(total, temp);
        temp = Q;
    }
    if (total < P) {
        cout << total << endl;
    } else {
        cout << P << endl;
    }
}