#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 8e18+7;

ll f(ll a, ll d, ll n) {
    return a + n*d;
}

int main() {
    ll X, A, D, N; cin >> X >> A >> D >> N;
    ll ans = inf;
    if (D < 0) {
        A = A+D*(N-1);
        D = -D;
    } 
    ll right = N-1;
    ll left = 0;
    while (right - left > 1) {
        ll mid = left - (left - right)/2;
        if (f(A, D, mid) >= X) right = mid;
        else left = mid;
    }
    for (ll i = max(0ll, right-5); i <= min((N-1), right+5); i++) {
        ans = min(ans, abs(A+D*i-X));
    }
    cout << ans << endl;
    return 0;
}