#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

int main() {
    ll N; cin >> N;
    ll power = 1;
    for (ll i = 0; i < N; ++i) {
        power = power * (i + 1) % mod;
    }

    cout << power % mod << endl;
    return 0;
}