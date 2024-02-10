#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > Grap;
static const ll INF = (1 << 60);

ll N, M, K, S;
ll P, Q;
vector<int> zombi_town(N, -1);
Grap depth(N, vector<ll>(N, 0));

void bfs(Grap& dis, Grap g, int s) {
    queue<int> q;
    q.push(s);
    vector<int> node(N, -1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        node[u] = 1;
        for (int v: g[u]) {
            if (node[v] > -1) continue;
            if (depth[s][v] <= S) {
                depth[s][v] = depth[s][u] + 1;
                dis[u][v] = Q;
                q.push(v);
            }
        }
    }
}

ll dijikstr(Grap grap, Grap dis) {
    priority_queue<pair<ll, int> > pq;
    pq.push(make_pair(0, 0));
    vector<int> node(N, 0);
    vector<ll> d(N, INF);
    while (!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        ll cost = -p.first;
        int u = p.second;
        node[u] = 1;
        if (d[u] < cost) continue;
        for (int v: grap[u]) {
            if (d[v] > dis[u][v] + cost) {
                d[v] = dis[u][v] + cost;
                pq.push(make_pair((-1) * d[v], v));
            }
        } 
    }
    return d[N-1];
}


int main() {
    cin >> N >> M >> K;
    cin >> P >> Q;
    for (int i = 0; i < K; i++) {
        int c; cin >> c;
        c--;
        zombi_town[c] = 1;
    }
    Grap g(N, vector<ll>(N));
    Grap dis(N, vector<ll>(N));
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        dis[a][b] = P;
        dis[b][a] = P;
    }
    for (int i = 0; i < K; i++) {
        int s = zombi_town[i];
        bfs(dis, g, s);
    }
    ll res = dijikstr(g, dis);
    cout << res << endl;
    return 0;
}