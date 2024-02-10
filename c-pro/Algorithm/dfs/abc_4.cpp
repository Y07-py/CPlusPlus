#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph& G, int v, int p, int d) {
    depth[v] = d;
    for (auto nv: G[v]) {
        if (nv == p) continue;
        dfs(G, nv, v, d+1);
    }

    subtree_size[v] = 1;
    for (auto c: G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c];
    }
}

int main() {
    return 0;
}