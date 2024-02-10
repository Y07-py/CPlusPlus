#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> num(N);
    for (int i = 0; i < N; i++) cin >> num[i];
    vector<vector<int> > dp(N + 1, vector<int>(21, 0));
    dp[0][num[0]] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 21; j++) {
            if (j - num[i] >= 0) {
                dp[i+1][j] += dp[i][j - num[i]];
            }
            if (j + num[i] <= 20) {
                dp[i+1][j] += dp[i][j + num[i]];
            }
        }
    }
    
    return 0;
}