#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

vector<int> color;

bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v: G[v]) {
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false;
            continue;
        }

        if (!dfs(G, next_v, 1 - cur)) return false;
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    
    return 0;
}