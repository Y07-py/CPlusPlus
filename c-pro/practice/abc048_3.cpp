#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    ll x; cin >> x;
    vector<ll> candy(N);
    ll ans = 0;

    for (int i = 0; i < N; ++i) {
        cin >> candy.at(i);
    }

    ll tmp_sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        ll a = candy.at(i);
        ll b = candy.at(i + 1);
        if (a + b > x) {
            candy.at(i + 1) -= a + b - x;
            ans += a + b - x;
        }
    }
    cout << ans << endl;
    return 0;
}