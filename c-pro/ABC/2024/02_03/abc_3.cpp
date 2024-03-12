#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll res = 0;
    for (int i = 0; i < N; i++) {
        res += A[i];
        if (res < 0) {
            res = 0;
        }
    }
    cout << res << endl;
    return 0;
}