#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int mod = 10000;

int main() {
    int N, K; cin >> N >> K;
    vector<int> pasta(N, -1);
    for (int i = 0; i < K; i++) {
        int A, B; cin >> A >> B;
        A--;
        pasta[A] = B;
    }
    vector<vector<int> > dp(N+2, vector<int>(3, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (int i = 0; i < N + 1; i++) {
        if (pasta[i] > -1) {
            for (int j = 0; j < 3; j++) {
                for (int s = 0; s < 3; s++) {
                    if (j == pasta[i] && s == pasta[i]) continue;
                    dp[i+2][pasta[i]] = dp[i][j] + dp[i+1][s];
                }
            }
        } else {
            for (int j = 0; j < 3; j++) {
                for (int s = 0; s < 3; s++) {
                    for (int l = 0; l < 3; l++) {
                        if (l == j && j == l && s == l) continue;
                        dp[i+2][l] = dp[i+1][j] + dp[i][s];
                    }
                }
            }
        }
    }
    cout << dp
    return 0;
}