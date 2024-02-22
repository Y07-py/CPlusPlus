#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll X, Y, Z; cin >> X >> Y >> Z;
    string S; cin >> S;
    int N = S.size();
    vector<vector<int> > dp(N+1, vector<int>(2, inf));
    dp[0][0] = 0;
    for (int i = 0; i < N+1; i++) {
        if (S[i] == 'A') {
            chmin(dp[i+1][0], dp[i][1] + Z + Y);
            chmin(dp[i+1][0], dp[i][0] + Y);
            chmin(dp[i+1][1], dp[i][1] + X);
            chmin(dp[i+1][1], dp[i][0] + Z + X)
        } else {
            chmin(dp[i+1][0], dp[i][1] + Z + X);
            chmin(dp[i+1][0], dp[i][0] + X);
            chmin(dp[i+1][1], dp[i][1] + Y);
            chmin(dp[i+1][1], dp[i][0] + Z + Y);
        }
    }
    chmin(dp[N][0], dp[N][1]);
    cout << dp[N][0] << endl;

    return 0;
}