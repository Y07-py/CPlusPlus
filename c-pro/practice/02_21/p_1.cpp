#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int, int>;
#define INf 1e18

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N; cin >> N;
    int w = 0;

    vector<P> data;
    for (int i = 0; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        int a = max(0, (y - x + 1)/2);
        w += z;
        data.emplace_back(a, z*2);
    }
    vector<vector<ll> > dp(N+1, vector<ll>(w+1, INf));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        pair<int, int> p = data[i];
        for (int j = 0; j < w+1; j++) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(w, j+p.second)], dp[i][j] + p.first);
        }
    }
    cout << dp[N][w] << endl;
    return 0;
}