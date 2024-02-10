#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    vector<int> memo(N);
    for (int i = 0; i < N; i++) cin >> memo[i];
    vector<vector<ll> > dp(N+1, vector<ll>(21, 0));
    dp[0][memo[0]] = 1;
    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j <= 20; j++) {
            if ( j - memo[i] >= 0) {
                dp[i][j - memo[i]] += dp[i-1][j];
            }
            if (j + memo[i] <= 20) {
                dp[i][j + memo[i]] += dp[i-1][j];
            }
        }
    }
    cout << dp[N-2][memo[N-1]] << endl;
    return 0;
}