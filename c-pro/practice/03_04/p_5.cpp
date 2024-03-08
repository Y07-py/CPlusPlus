#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
#define rep(i, n) for (int i = 0; i < N; i++) {}


int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<ll> > dp(N+1, vector<ll>(10, 0));
    dp[1][A[0]] = 1;
    
   for (ll i = 1; i < N; i++) {
    for (ll j = 0; j < 10; j++) {
        dp[i+1][(j + A[i])%10] += dp[i][j]%mod;
        dp[i+1][(j * A[i])%10] += dp[i][j]%mod;
    }
   }

   for (int i = 0; i < 10; i++) {
    cout << dp[N][i]%mod << endl;
   }
    return 0;
}