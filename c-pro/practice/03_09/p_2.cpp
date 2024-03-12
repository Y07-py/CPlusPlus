#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> mp;

ll solve(ll x) {
    if (x < 2) return 0;
    if (mp.find(x) != mp.end()) return mp[x];
    mp[x] = solve(x/2) + solve((x+1)/2) + x;
    return mp[x];
}

int main() {
    ll N; cin >> N;
    ll ans = solve(N);
    cout << ans << endl;
    return 0;
}