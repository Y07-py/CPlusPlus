#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll mod = 1000000007;
    ll N; 
    cin >> N;
    
    map<ll, ll> mp;
    for (ll i = 1; i <= N; ++i) {
        ll m = i;
        for (int j = 2; j <= i; ++j) {
            while (m%j == 0) {
                mp[j] += 1;
                m /= j;
            }
        }
    } 

    ll ans = 1;
    for (auto [d, c]: mp) {
        ans *= (c + 1);
        ans %= mod;
    }
    cout << ans % mod << endl;

}

