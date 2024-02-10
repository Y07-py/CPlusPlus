#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }
    vector<vector<bool> > dp(N+1, vector<bool>(10001));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10001; j++) {
            if (!(dp[i][j])) continue;
            dp[i+1][j] = true;
            if (j + points[i] <= 10000) dp[i+1][j + points[i]] = true;
        }
    }

    ll res = 0;
    for (int i = 0; i < 10001; i++) {
        if (dp[N][i]) res++;
    }

    cout << res << endl;

    return 0;
}