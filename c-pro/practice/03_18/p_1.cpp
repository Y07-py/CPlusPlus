#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll> > cnt;
ll ans = 0;
int N, X, Y;

ll f(ll n, ll c) {
    if (n == 1) {
        if (c == 0) {
            return 0;
        } else {
            return 1;
        }
    }

    if (c == 0) {
        return f(n-1, 0) + f(n, 1)*X;
    } else {
        return f(n-1, 0) + f(n-1, 1)*Y;
    }
}

int main() {
    cin >> N >> X >> Y;
    ll ans = f(N, 0);
    cout << ans << endl;
}