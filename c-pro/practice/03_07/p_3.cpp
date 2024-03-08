#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, D; cin >> N >> D;
    vector<pair<ll, ll> > P(N);

    for (int i = 0; i < N; i++) cin >> P[i].second >> P[i].first;
    sort(P.begin(), P.end());
    int ans = 0;
    int x = -1;
    for (auto [r, l]: P) {
        if (l <= x) continue;
        ++ans;
        x = r+D-1;
    }
    cout << ans << endl;
    return 0;
}