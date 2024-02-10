#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1 << 30;
const ll MAX_W = 10101;
const ll MAX_N = 60;


template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll W; cin >> W;
    ll N, K; cin >> N >> K;
    vector<ll> A(N+1);
    vector<ll> B(N+1);

    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    vector<vector<vector<ll> > > dp(MAX_N, vector<vector<ll> >(MAX_W, vector<ll>(K+1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N+1; i++) {
        for (int total_w = 0; total_w < MAX_W; total_w++) {
            for (int k = 0; k < K+1; k++) {
                if (i == 0) dp[i][total_w][k] = 0;
                if (total_w - A[i] >= 0) {
                    chmax(dp[i+1][total_w][k+1], dp[i][total_w - A[i]][k] + B[i]);
                }
                chmax(dp[i+1][total_w][k+1], dp[i][total_w][k]);
            }
        }
    }
    cout << dp[1][W][K] << endl;
    return 0;
}
