#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int K;
ll INF = 10101010;

vector<pair<int, ll> > edge[5010];
vector<vector<int> > G(N);
vector<int> R(N);
vector<int> C(N);

void bfs() {
    for (int i = 0; i < N; i++) {
        queue<int> que;
        vector<ll> dist(N, -1);
        que.push(i);
        dist[i] = 0;

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& u: G[v]) {
                if (dist[u] != -1) continue;
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (dist[j] <= R[i]) {
                edge[i].push_back(make_pair(j, dist[j]));
            }
        }
    }
}

ll dijikstr(int s) {
    priority_queue<pair<int, ll> > pq;
    vector<int> dist(N, INF);
    dist[s] = 0;
    pq.push(make_pair(s, dist[s]));

    while (!pq.empty()) {
        pair<int, ll> p = pq.top(); pq.pop();
        int from = p.first;
        ll d = (-1) * p.second;
        if (dist[from] < d) continue;

        for (auto& nv: edge[from]) {
            int to = nv.first;
            ll cost = nv.second;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                pq.push(make_pair(to, (-1) + dist[to]));
            }
        }
    }
    return dist[N-1];
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> R[i];
    }
    for (int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        a--, b--,
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs();
    int res = dijikstr(0);
    cout << res << endl;
    return 0;
}