#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;


int main() {
    int N,  M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> queue;

    dist[0] = 0;
    queue.push(0);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (int nv: G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            queue.push(nv);
        }
    }

    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;

}