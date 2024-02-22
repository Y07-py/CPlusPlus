#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)2e+18


int main() {
    ll N, M; cin >> N >> M;
    ll ans = INF;
    for (ll i = 1; i <= sqrt(M); i++) {
        ll b = (M + i - 1) / i;
        if (b <= N) ans = min(ans, i*b);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}