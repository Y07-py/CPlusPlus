#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> memo;

ll solve(ll x) {
    if (x == 1) {
        return 0;
    }
    if (memo[x] != 0) return memo[x];
    return memo[x] = solve(x/2) + solve((x+1)/2) + x;
}

int main() {
    ll N; cin >> N;
    ll res = solve(N);
    cout << res << endl;
    return 0;
}