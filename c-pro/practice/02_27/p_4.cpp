#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main() {
    string S; cin >> S;
    int n; n = S.size();
    vector<vector<int> > dp(n+1, vector<int>(9));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    string t = "chokudai";
    for (int i = 0; i< n; i++) {
        for (int j = 0; j < 8; j++) {
            if (S[i] != t[j]) {
                dp[i+1][j+1] = dp[i][j+1];
            } else {
                dp[i+1][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n][8] % mod << endl;
    
    return 0;
}