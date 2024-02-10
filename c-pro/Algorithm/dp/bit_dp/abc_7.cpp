#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e8

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
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
    vector<vector<ll> > dp(N+1, vector<ll>(100000, 0));
    for (int i = 0; i < N; i++) {
        for (int v = 0; v <= 100000; v++) {
            if (v - V_[i] >= 0) {
                chmin(dp[i+1][v], dp[i][v - V_[i]] + W_[i]);
            } else {
                chmin(dp[i+1][v], dp[i][v]);
            }
        }
    }
    for (int i = 100000; i >= 0; i--) {
        if (dp[N][i] <= W) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}