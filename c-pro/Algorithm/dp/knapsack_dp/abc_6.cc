#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL << 20
#define mod 1000000007

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> broken(M);
    vector<bool> issafe(N, true);
    vector<ll> dp(N+1);
    for (int i = 0; i < M; i++) {
        ll a; cin >> a;
        issafe[a] = false;
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N + 1; i++) {      
        if (issafe[i-1]) dp[i] += dp[i-1];
        if (issafe[i-2]) dp[i] += dp[i-2];
        dp[i] %= mod;
    }

    cout << dp[N] << endl;
    return 0;
}