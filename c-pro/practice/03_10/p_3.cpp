#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll inv2 = 499122177;

ll triangular_number(ll x) {
    x %= mod;
    ll res = x;
    res *= (x+1); res %= mod;
    res *= inv2; res %= mod;
    return res;

}

int main() {
    ll N; cin >> N;
    ll res = 0;
    ll p10 = 10;
    for (int dg = 1; dg < 19; dg++) {
        ll l = p10 / 10;
        ll r = min(N, p10-1);
        if (l <= r) {
            res += triangular_number(r-l+1);
            res %= mod;
            p10 *=10;
        }
    }
    cout << res << endl;
    return 0;
}