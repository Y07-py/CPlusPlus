#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }
    vector<vector<ll> > dp(N+1, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 0; i < N; i++) {
        if (A[i+1] != A[i]) {
            dp[i+1][0] += dp[i][0];
        }
        if (A[i+1] != B[i]) {
            dp[i+1][0] += dp[i][1];
        }
        if (B[i+1] != A[i]) {
            dp[i+1][1] += dp[i][0];
        }
        if (B[i+1] != B[i]) {
            dp[i+1][1] += dp[i][1];
        }
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }
    cout << (dp[N-1][0] + dp[N-1][1]) % mod << endl;
    return 0;
}