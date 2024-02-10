#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX = (1 << 21);

int main() {
    int N, W; cin >> N >> W;
    vector<pair<int, int> > pr(N);
    for (int i = 0; i < N; i++) {
        cin >> pr[i].first >> pr[i].second;
    }
    vector<vector<int> > dp(N+1, vector<int>(W+1));
    for (int  i = 0; i < N; i++) {
        for (int w = 0; w < W+1; w++) {
            if (w - pr[i].first >= 0) {
                dp[i+1][w] = max(dp[i][w], dp[i][w - pr[i].first] + pr[i].second);
            } else {
                dp[i+1][w] = dp[i][w];
            }

        }
    }
    int ans = dp[N][W];
    cout << ans << endl;
    return 0;
}