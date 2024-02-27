#include <bits/stdc++.h>
using namespace std;
#define inf 1e6

template <class T> inline void chmin(T &a, T b) {if (a > b) a = b;};

int main() {
    int N; cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];
    int dp[N+1][102010];
    for (int i = 0; i < N+1; i++) {
        for (int t = 0; t < 102010; t++) {
            dp[i][t] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int t = 0; t < 101010; t++) {
            chmin(dp[i+1][t+T[i]], dp[i][t]);
            chmin(dp[i+1][t], dp[i][t] + T[i]);
        }
    }

    int ans = inf;
    for (int t = 0; t < 101010; t++) {
        chmin(ans, max(t, dp[N][t]));
    }
    cout << ans << endl;
    return 0;
}