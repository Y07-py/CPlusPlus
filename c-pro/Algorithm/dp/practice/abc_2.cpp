#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(H[1] - H[0]);
    for (int i = 2; i < N; i++) {
        dp[i] = dp[i-1] + abs(H[i-1] + H[i]);
        for (int j = 2; j < K + 1; j++) {
            if (i - j >= 1) {
                dp[i] = min(dp[i], dp[i - j] + abs(H[i - j] + H[i]));
            }
        }
    }
    return 0;
}