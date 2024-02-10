#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, W; cin >> N >> W;
    vector<ll> weight(N);
    vector<ll> value(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }
    vector<vector<ll> > dp(N+1, vector<ll>(W+1));

    for (int i = 0; i < N; i++) {
        for (int sum_w = 0; sum_w <= W; sum_w++) {
            if (sum_w - weight[i] >= 0) {
                chmax(dp[i+1][sum_w], dp[i][sum_w - weight[i] + value[i]]);
            }
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }
    return 0;
}