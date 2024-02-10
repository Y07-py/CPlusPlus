#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL << 30;

const int MAX_V = 100100;
const int MAX_N = 110;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll N, W; cin >> N >>W;
    vector<ll> weight(N+1);
    vector<ll> value(N+1);
    for (int i = 0; i < N; i++) {
        ll w, v; cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    vector<vector<ll> > dp(MAX_N, vector<ll>(MAX_V));

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_V; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int sum_v = 0; sum_v < MAX_V; sum_v++) {
            if (sum_v - value[i] >= 0) {
                chmin(dp[i+1][sum_v], dp[i][sum_v - value[i]] + weight[i]);
            }
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }
    ll res = 0;
    for (int sum_v = 0; sum_v < MAX_V; sum_v++) {
        if (dp[N][sum_v] <= W) res = sum_v;
    }
    cout << res << endl;
    return 0;
}