#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> results(N);
    for (int i = 0; i < N; i++) cin >> results[i];
    vector<vector<ll> > dp(N+1, vector<ll>(21, 0));
    dp[0][results[0]] = 1;
    for (int i = 1; i < N; i++) {
        ll num = results[i];
        for (int j = 0; j <= 20; j++) {
            if (num + j <= 20) {
                dp[i][j + num] += dp[i-1][j];
            }
            if (j - num >= 0) {
                dp[i][j - num] += dp[i-1][j];
            }
        }
    }
    cout << dp[N-2][results[N-1]] << endl;
    return 0;
}