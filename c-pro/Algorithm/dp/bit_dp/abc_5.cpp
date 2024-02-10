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
    int N; cin >> N;
    vector<vector<int> > input(N+1, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> input[i][j];
        }
    }
    vector<vector<int> > dp(N+1, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        chmax(dp[i+1][0], max(dp[i][1] + input[i][0], dp[i][2] + input[i][0]));
        chmax(dp[i+1][1], max(dp[i][0] + input[i][1], dp[i][2] + input[i][1]));
        chmax(dp[i+1][2], max(dp[i][0] + input[i][2], dp[i][1] + input[i][2]));
    }
    int res = 0;
    for (int i = 0; i < 3; i++) {
        res = max(res, dp[N][i]);
    }
    cout << res << endl;
    return 0;
}