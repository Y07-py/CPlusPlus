#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, W; cin >> N >> W;
    vector<int> W_(N);
    vector<int> V_(N);
    for (int i = 0; i < N; i++) {
        int w, v; cin >> w >> v;
        W_[i] = w;
        V_[i] = v;
    }
    vector<vector<int> > dp(N+1, vector<int>(W+1, 0));
    for (int i = 0; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            if (w - W_[i] >= 0) {
                chmax(dp[i+1][w], dp[i][w - W_[i]] + V_[i]);
            } else {
                chmax(dp[i+1][w], dp[i][w]);
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}