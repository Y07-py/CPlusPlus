#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main() {
    string S; cin >> S;
    int size = S.size();
    vector<vector<ll> > dp(size+1, vector<ll>(9, 0));
    for (int i = 0; i < size+1; i++) dp[i][0] = 1;
    string T = "chokudai";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            if (S[i] == T[j]) dp[i+1][j+1] = (dp[i][j] + dp[i][j+1]) % mod;
            else dp[i+1][j+1] = dp[i][j+1];
        }
    }
    cout << dp[size][8] << endl;
    return 0;
}