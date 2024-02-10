#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 110000;
ll N;
vector<ll> dp(INF, INF);

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

ll rec(ll n) {
    if (n <= 0) return 0;
    if (dp[n] != INF) return dp[n];

    ll res = n;
    for (int i = 1; i <= N; i *= 6) {
        chmin(res, rec(N - i) + 1);
    }
    for (int i = 1; i <= N; i *= 9) {
        chmin(res, rec(N - i) + 1);
    }
    return dp[n] = res;
}

int main() {
    cin >> N;
    ll res = rec(N);
    cout << res << endl;
    return 0;
}