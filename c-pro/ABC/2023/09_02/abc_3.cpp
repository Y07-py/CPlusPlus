#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int INF = (1 << 21);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, D, P; cin >> N >> D >> P;
    vector<ll> F(N);
    for (int i = 0; i < N; i++) cin >> F[i];
    sort(F.begin(), F.end());
    vector<ll> dp(N+1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1] = min(dp[i], dp[i] + F[i]);
    }
    cout << dp[N] << endl;
    return 0;
}