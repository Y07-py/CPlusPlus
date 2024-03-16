#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limit = 1e6+7;

int main() {
    ll N; cin >> N;
    vector<int> prime(limit+1, 1);
    vector<int> primes;
    prime[0] = 0;
    prime[1] = 0;
    for (int q = 2; q < limit+1; q++) {
        if (prime[q]) {
            primes.push_back(q);
            for (ll j = (ll)q*q; j < limit+1; j += q) prime[j] = 0;
        }
    }
    vector<int> S(limit+1);
    for (int p: primes) {
        S[p] = 1;
    }
    for (int i = 0; i < limit; i++) S[i+1] += S[i];
    ll ans = 0;
    for (int q: primes) {
        ll r = min<ll>(N/q/q/q, q-1);
        ans += S[r];
    }
    cout << ans << endl;
    return 0;
}