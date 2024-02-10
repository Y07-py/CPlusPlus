#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL << 30

int main() {
    int N, M; cin >> N >> M;
    vector<int> dis(N);
    vector<int> temp(M);
    for (int i = 0; i < N; i++) cin >> dis[i];
    for (int i = 0; i < M; i++) cin >> temp[i];

    vector<vector<ll> > dp(N+1, vector<ll>(M+1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    
    for (int i = 0; i < N; i++) {
        ll v = INF;
        for (int j = i; j <= M - N + i; j++) {
            v = min(v, dp[i][j]);
            dp[i+1][j+1] = min(dp[i+1][j+1], v + temp[j] * dis[i]);
        }
    }
    ll ans = dp[N][M];
    for (int i = N; i < M; i++) {
        ans = min(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}