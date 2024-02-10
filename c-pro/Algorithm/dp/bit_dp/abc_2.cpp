#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 1LL << 20
#define rp(i, n) for (int i = 0; i < n; i++)

template <class S, class T>
inline bool chmin(S &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

struct edge {
    ull to;
    ull dist;
    ull time;
    edge() {}
    edge(const ull &to, const ull &d, const ull &time) : to(to), dist(d), time(time) {}
};

int main() {
    int n, m; cin >> n >> m;
    using graph = vector<vector<edge>>;
    graph g(n);
    rp(i, m) {
        ull u, v, d, t;
        cin >> u >> v >> d >> t;
        --u, --v;
        g[u].emplace_back(v, d, t);
        g[v].emplace_back(u, d, t);
    }

    const ll setbit = 1 << n;
    using pll = pair<ll, ll>;
    vector<vector<pll>> dp(setbit, vector<pll>(n, {INF, 0}));
    dp[0][0] = {0, 1};

    for (ll bit = 0; bit < setbit; bit++) rp(v, n) for (auto &e: g.at(v)) {
        if (bit != 0 && !((1 << v) & bit)) continue;
        const auto cost = e.dist + dp[bit][v].first;
        const auto u = e.to;

        if (!(bit & (1 << u)) && cost <= e.time) {
            auto &dest = dp[bit | (1 << u)][u];
            if (dest.first == cost) {
                dest.second += dp[bit][v].second;
            } else {
                if (chmin(dest.first, cost)) {
                    dest.second = dp[bit][v].second;
                }
            }
        } 
    }

    
}