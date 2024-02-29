#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll inf = 1e9;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > to(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> dist(N+1, inf);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    vector<int> vs;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        vs.push_back(v);
        for (int u: to[v]) {
            if (dist[u] != inf) continue;
            dist[u] = dist[v] + 1;
            que.push(u);
        }
    }

    vector<int> dp(N);
    dp[0] = 1;
    for (int v: vs) {
        for (int u: to[v]) {
            if (dist[u] == dist[v] + 1) {
                dp[u] += dp[v] % mod;
            }
        }
    }
    cout << dp[N-1] % mod << endl;

    return 0;
}