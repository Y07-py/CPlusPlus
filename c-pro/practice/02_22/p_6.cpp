#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define inf 1e18;

int main() {
    int N; cin >> N;
    vector<vector<int> > dp(N+1, vector<int>(2, -inf));
    dp[0][0] = 0; 
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        ll y; cin >> y;
        if (x) {
            dp[i+1][1] = max(dp[i][0] + y, dp[i][1]);
        } else {
            dp[i+1][0] = max(dp[i][0], max(dp[i][0], dp[i][1])+y);
        }
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
    }
    ll res = max(dp[N-1][0], dp[N-1][1]);
    cout << res << endl;
    return 0;
}