#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
    int N; cin >> N;
    vector<vector<ll> > dp(N+1, vector<ll>(10, 0));
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < 10; j++) {
            if (j-1 >= 1) {
                dp[i+1][j-1] += (dp[i][j] % mod);
                dp[i+1][j-1] % mod;
            }
            dp[i+1][j] += (dp[i][j] % mod);
            dp[i+1][j] % mod;
            if (j+1 <= 9) {
                dp[i+1][j+1] += (dp[i][j] % mod);
                dp[i+1][j+1] % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < 10; i++) {
        ans += (dp[N][i] % mod);
    }
    cout << ans % mod << endl;
    return 0;
}