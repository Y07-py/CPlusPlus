#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main() {
    int N; cin >> N;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll tmp = C[i] - i;
        ans *= tmp;
        ans %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}