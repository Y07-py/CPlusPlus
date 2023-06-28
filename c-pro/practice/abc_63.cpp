#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, A[101010];
int dp[101][10101];

void main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if (dp[i][j]) {
                dp[i+1][j] = 1;
                dp[i+1][j + A[i]] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 1001; ++i) {
        if (i % 10  && dp[N][i]) ans = max(ans, i);
    }
    cout << ans << endl;
}