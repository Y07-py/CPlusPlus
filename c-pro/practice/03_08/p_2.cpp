#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> S(N+1, 0);
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }
    map<ll, int> mp;
    ll ans = 0;
    for (int i = 0; i < N+1; i++) {
        ans += mp[S[i]];
        mp[S[i]+K]++;
    }
    cout << ans << endl;
    return 0;
}