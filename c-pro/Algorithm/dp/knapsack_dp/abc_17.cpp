#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, W; cin >> N >> W;
    vector<ll> W_(N);
    vector<ll> V_(N);

    for (int i = 0; i < N; i++) {
        ll w, v; cin >> w >> v;
        W_.push_back(w);
        V_.push_back(v);
    }

    vector<vector<int> > dp(N+1, vector<int>(W+1, 0));

    for (int i = 0; i < N; i++) {
        int w = W_[i];
        int v = V_[i];
        for (int j = 0; j <= W; j++) {
            if (j + w <= W) {
                chmax(dp[i+1][j + w], dp[i][j] + v);
            }
            else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[N-1][W] << endl;
    
    return 0;
}