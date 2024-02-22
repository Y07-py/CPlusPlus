#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res = 0;

ll solve(ll a, ll b) {
    if (a == 1 || b == 1) {
        return a + b;
    }
    solve(a/2, a - a/2);
    solve(b/2, b - b/2);
    return a + b;
}

int main() {
    ll N; cin >> N;
    ll ans = N;
    ans += solve(N/2, N - N/2);
    cout << res << endl;
    return 0;
}