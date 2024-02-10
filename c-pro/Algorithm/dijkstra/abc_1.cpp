#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<pair<ll, ll> > > graph;
static const int MAX_N = 110;
static const int INF = (1 << 30);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BRACK = 2;

int N, K;

ll dijkstra(graph G, ll N, ll start, ll end) {
    priority_queue<pair<int, int> > pq;
    vector<int> colors(N);
    vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        colors[i] = WHITE;
        cost[i] = INF; 
    }
    cost[start] = 0;
    colors[start] = GRAY;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> first = pq.top();
        pq.pop();
        int u = first.second;
        colors[u] = BRACK;

        if (cost[u] < first.first * (-1)) continue;
        for (auto& e: G[u]) {
            int v = e.first;
            int w = e.second;
            if (colors[v] == BRACK) continue;
            if (cost[v] > cost[u] + w) {
                cost[v] = cost[u] + w;
                pq.push(make_pair(cost[v]*(-1), v));
                colors[v] = GRAY;
            }
        }
    }
    return cost[end];
}

int main() {
    cin >> N >> K;
    vector<vector<pair<ll, ll> > > G(MAX_N);
    vector<bool> node(N);
    vector<ll> ans;
    for (int i = 0; i < K; i++) {
        int f; cin >> f;
        if (f == 1) {
            int a, b, w; cin >> a >> b >> w;
            G[a-1].push_back(make_pair(b-1, w));
            G[b-1].push_back(make_pair(a-1, w));
            node[a-1] = true;
            node[b-1] = true;
        } else {
            int a, b; cin >> a >> b;
            if (!node[a-1] || !node[b-1]) cout << -1 << endl;
            else {
                ll n = G.size();
                ll res = dijkstra(G, n, a-1, b-1);
                cout << res << endl;
            }
        }
    }
    return 0;
}