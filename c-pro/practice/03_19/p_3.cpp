#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> mp;
ll f(ll k) {
    if (k == 0) return 1;
    if (mp.find(k) != mp.end()) return mp[k];
    return mp[k] = f(k/2) + f(k/3); 
}

int main() {
    ll N; cin >> N;
    ll res = f(N);
    cout << res << endl;
    return 0;
}