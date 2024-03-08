#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9+7;

vector<vector<ll> > A;

int main() {
    ll N; cin >> N;
    vector<ll> T(N);
    A.resize(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll t, k; cin >> t >> k;
        for (int j = 0; j < k; j++) {
            ll a; cin >> a;
            a--;
            A[i].push_back(a);
        }
        T[i] = t;
    }
    vector<bool> need(N);
    need[N-1] = true;
    for (int i=N-1; i > -1; i--) {
        if (need[i]) {
            for (ll e: A[i]) {
                need[e] = true;
            }
        }
    }
    for (int i=0; i < N; i++) {
        if (need[i]) ans += T[i];
    }
    cout << ans << endl;
    return 0;
}