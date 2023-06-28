#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1ll<<60;

int calc_digit(ll n) {
    int res = 0;
    while (n > 0) {
        ++res;
        n /= 10;
    }
    return res;
}

int main() {
    ll N; cin >> N;
    ll res = INF;
    for (ll a = 1; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll b = N / a;
        ll tmp = max(calc_digit(a), calc_digit(b));
        res = min(res, tmp);
    }

    cout << res << endl;
    return 0;
}