#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    ll K; cin >> K;

    vector<vector<ll> > dp(61, vector<ll>(61, 0));
    dp[0][0] = 1;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < i+1; j++) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j+1] += dp[i][j];
        }
    }
    string ans;
    while (A + B > 0) {
        ll x = 0;
        if (A >= 1) x = dp[A+B-1][A-1];
        if (x >= K) {
            ans += 'a';
            A--;
        } else {
            ans += 'b';
            B--;
            K -= x;
        }
    }
    cout << ans << endl;
    return 0;
}