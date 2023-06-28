#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> array(N);
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        array[a] += b;
    }

    for (int i = 1; i < 100000; ++i) {
        if (K <= array[i]) {
            cout << i << endl;
        }
        K -= array[i];
    }

    return 0;
}