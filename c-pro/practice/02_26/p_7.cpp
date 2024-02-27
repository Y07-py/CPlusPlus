#include <bits/stdc++.h>
using namespace std;
#define inf 1e8
typedef long long ll;

vector<vector<int> > graph;
vector<vector<int> > dis;


ll dijikistr(int s, int t, int N, int K) {
    priority_queue<pair<ll, int> > pq;
    pq.push(make_pair(0, s));
    vector<int> check(N, 0);
    vector<ll> node(N, inf);

    while (!pq.empty()) {
        pair<ll, int> p = pq.top();
        pq.pop();
        ll d = -p.first;
        ll u = p.second;
        check[u] = 1;
        if (node[u] < d) continue;
        for (auto& v: graph[u]) {
            if (K < v) continue;
            if (check[v]) continue;
            if (node[v] > node[u] + dis[u][v]) {
                node[v] = node[u] + dis[u][v];
                pq.push(make_pair(-node[v], v));
            }
        }
    }
    return node[t];
}

int main() {
    int N, M; cin >> N >> M;
    graph.assign(N, vector<int>(N));
    dis.assign(N, vector<int>(N, inf));
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(b);
        dis[a][b] = c;
    }
    ll ans = 0;
    for (int s = 0; s < N; s++) {
        for (int t = 0; t < N; t++) {
            for (int k = 0; k < N; k++) {
                if (s == t) continue;
                ll res = dijikistr(s, t, N, k);
                if (res != inf) ans += res;
            }
        }
    }
    cout << ans << endl;
    return 0;
}