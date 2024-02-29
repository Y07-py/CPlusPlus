#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> S(N);
    vector<ll> T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];
    vector<ll> res(N);
    res[0] = T[0];
    for (int i = 0; i < N*2; i++) {
        if (res[i%N] + S[i%N] < T[(i+1)%N]) {
            res[(i+1)%N] = res[i%N] + S[i%N];
        } else {
            res[(i+1)%N] = T[(i+1)%N];
        }
    }
    for (int i = 0; i < N; i++) cout << res[i] << endl;
    return 0;
}