#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double f(ll x, ll a, ll b) {
    return (double) a / sqrt(x+1) + (double)b*x;
}

int main() {
    ll A, B; cin >> A >> B;
    ll x = pow((double) A / (B * 2), 2. / 3.)-1;
    ll l = max(x-5, 0LL);
    ll r = min(x+5, A/B);
    double ans = A;
    for (ll i = l; i < r + 1; i++) {
        ans = min(ans, f(i, A, B));
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}