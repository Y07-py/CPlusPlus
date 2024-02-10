#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h[100010];
ll dp[100010];

template<class T> inline bool chmax(T &a, T b) {
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
    }
    return false;
}

const ll INF = 1LL << 60;

ll rec(int i) {
    int res;
    if (dp[i] < INF) return dp[i];
    if (i == 0) return 0;
    chmin(dp[i], rec(i-1) + abs(h[i] - h[i - 1]));
    if (i > 1) {
        chmin(dp[i], rec(i-2) + abd(h[i] - h[i-2]))；
    }
    res = dp[i];
    return res;
}

int main() {
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < 100010; i++) {
        dp[i] = INF;
    }

    for (int i = 0; i < N; i++) {
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if (i > 1) {
            chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
    }

    cout << dp[N-1] << endl;
    return 0;
}

