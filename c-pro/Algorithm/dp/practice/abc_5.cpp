#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, W; cin >> N >> W;
    vector<ll> w(N);
    vector<ll> v(N);
    for (int i = 0; i < N; i++) {
        ll w_i, v_i; cin >> w_i >> v_i;
        w[i] = w_i;
        v[i] = v_i;
    }
    
    return 0;
}