#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int INF = (1 << 20);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector< ll > > dp(N, vector<ll>(N, INF));

    for (int i = 0; i < M; i++) {
        int a, b, t; cin >> a >> b >> t;
        a--; b--;
        dp[a][b] = t;
        dp[b][a] = t;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dp[k][i] == INF) continue;
            for (int j = 0; j < N; j++) {
                if (dp[k][j] == INF) continue;
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll res = INF;
    vector<ll> temp(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            chmax(temp[i], dp[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        chmin(res, temp[i]);
    }
    cout << res << endl;
    return 0;
}