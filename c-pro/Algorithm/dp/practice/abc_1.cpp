#include <bits/stdc++.h>
using namespace std;
static const int INF = (1 << 21);

int main() {
    int N; cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    vector<int> dp(INF+1, 0);
    dp[0] = 0;
    dp[1] = abs(H[1] - H[0]);
    dp[2] = abs(H[2] - H[0]); 
    for (int i = 3; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(H[i] - H[i-1]), dp[i-2] + abs(H[i] - H[i-2]));
    }
    return 0;
}