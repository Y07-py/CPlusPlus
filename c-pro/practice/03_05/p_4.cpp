#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<vector<ll> > dp(N+1, vector<ll>(3001, 0));

    dp[0][0] = 1;
    vector<ll> S(3001);
    for (int i = 0; i < N; i++) {
        S[0] = dp[i][0];
        for (int j = 1; j < 3001; j++) {
            S[j] = (S[j-1]%mod + dp[i][j]%mod) % mod;
        }
        for (int j = A[i]; j < B[i]+1; j++) {
            dp[i+1][j] += S[j] % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 3001; i++) {
        ans += dp[N][i] % mod;
    }
    cout << ans << endl;
    return 0;
}