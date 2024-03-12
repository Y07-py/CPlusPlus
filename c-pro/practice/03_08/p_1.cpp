#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll X;
vector<vector<ll> > A;
int ans;

void dfs(int i, ll s) {
    if (i == N) {
        if (s == X) ans++;
        return;
    }

    for (ll e: A[i]) {
        if (s*e > X) continue;
        dfs(i+1, s*e);
    }
}

int main() {
    cin >> N >> X;
    A.resize(N);
    vector<ll> L(N);
    for (ll i = 0; i < N; i++) {
        ll l; cin >> l;
        L[i] = l;
        for (ll j = 0; j < l; j++) {
            ll a; cin >> a;
            A[i].push_back(a);
        }
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}