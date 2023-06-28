#include <bits/stdc++.h>
using namespace std;

long long N, A;
vector<long long> x;
long long dp[55][55][2555] = {0};

long long solve();

int main() {
    cin >> N >> A;
    for (int i = 0; i < N; i++) {
        int nx;
        cin >> nx;
        x.push_back(nx);
    }
    cout << solve() << endl;
}

long long solve() {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int now  = x[i];
        if (i != 0) {
            for (int j = 1; j <= i + 1; j++) {
                for (int k = 0; k <= 2550; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
        dp[i][1][now] += 1;
        if ( i != 0) {
            for (int j = 1; j <= i + 1; j++) {
                for (int k = 0; k  + now <= 2550; k++) {
                    dp[i][j][k + now] += dp[i - 1][j - 1][k];
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        ans += dp[N - 1][i][i * A];
    }
    return ans;
}

