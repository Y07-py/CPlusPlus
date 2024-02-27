#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > E, int s) {
    vector<int> dist(E.size(), -1);
    dist[s] = 0;
    queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int q = que.front();
        que.pop();
        for (auto &e: E[q]) {
            if (dist[e] != -1) continue;
            dist[e] = dist[q] + 1;
            que.push(e);
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main() {
    int N1, N2, M; cin >> N1 >> N2 >> M;
    vector<vector<int> > node(N1+N2);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    int ans_1 = bfs(node, 0);
    int ans_2 = bfs(node, N1+N2-1);
    cout << ans_1 + ans_2 + 1 << endl;


    return 0;
}