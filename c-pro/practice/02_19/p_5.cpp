#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353

ll c_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int Q; cin >> Q;
    ll S = 1;
    queue<ll> que;
    que.push(1);
    for (int q = 0; q < Q; q++) {
        int i; cin >> i;
        if (i == 1) {
            int x; cin >> x;
            S = (10 * S + x) % mod;
            que.push(x);
        } else if (i == 2) {
            int x = que.front();
            ll size = que.size();
            S = (S - (c_pow(10, que.size()-1) * x)) % mod;
            que.pop();
        } else {
            cout << S % mod << endl;
        }
    }
    return 0;
}