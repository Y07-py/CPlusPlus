#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    vector<vector<bool> > dp(N+1, vector<bool>(2));
    dp[0][1] = true;
    dp[0][0] = true;

    for (int i = 0; i < N-1; i++) {
        if (dp[i][0]) {
            if (abs(A[i+1] - A[i]) <= K) dp[i+1][0] = true;
            if (abs(B[i+1] - A[i]) <= K) dp[i+1][1] = true;
        }
        if (dp[i][1]) {
            if (abs(A[i+1] - B[i]) <= K) dp[i+1][0] = true;
            if (abs(B[i+1] - B[i]) <= K) dp[i+1][1] = true; 
        }
    }
    if (dp[N-1][0] || dp[N-1][1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}