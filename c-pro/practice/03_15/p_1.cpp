#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> X(N+1);
    vector<int> R(N);
    for (int i = 0; i < N; i++) {
        X[i+1] = i;
        R[i] = i+1;
    }
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        if (X[x] < N-1) {
            int y = X[x]+1;
            swap(R[X[x]], R[y]);
            swap(X[x], X[R[X[x]]]);
        } else {
            int y = X[x]-1;
            swap(R[y], R[X[x]]);
            swap(X[x], X[R[X[x]]]);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << R[i] << " ";
    }
    cout << endl;
    return 0;
}