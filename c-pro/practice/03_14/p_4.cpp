#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<ll> > dp(N+1, vector<ll>(K+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 1; k < M+1; k++) {
                if (j + k <= K) {
                    dp[i+1][j+k] += dp[i][j] % mod; 
                }
            }
        }
    } 
    ll ans = 0;
    for (int i = 1; i < K+1; i++) {
        ans += dp[N][i] % mod;
    }
    cout << (ans % mod) << endl;
    return 0;
}