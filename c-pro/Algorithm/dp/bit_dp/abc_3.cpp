#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e8

int main() {
    int N; cin >> N;
    vector<int> H(N+1, 0);
    for (int i = 1; i < N+1; i++) {
        cin >> H[i];
    }
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N+1; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(H[i+1] - H[i]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(H[i+2] - H[i]));
    }
    cout << dp[N-1] << endl;
    return 0;
}