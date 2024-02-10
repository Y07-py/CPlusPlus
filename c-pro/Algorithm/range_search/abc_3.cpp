#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;

struct LowLink {
    const Graph &G;
    vector<int> used, ord, low;
    vector<int> aps;
    vector<P> brideges;

    LowLink(const Graph &G_) : G(G_) {
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)G.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
    }

    int dfs(int id, int k, int par) {
        used[id] = true;
        ord[id] = k++;
        low[id] = ord[id];
        bool is_aps = false;
        int count = 0;
        for (auto &e: G[id]) {
            if (!used[e.to]) {
                count++;
                k  = dfs(e.to, k, id);
                low[id] = min(low[id], low[e.to]);
                if (par != -1 && ord[id] <= low[e.to]) is_aps = true;
                if (ord[id] < low[e.to]) brideges.emplace_back(min(id, e.to), max(id, e.to));
            } else if (e.to != par) {
                low[id] = min(low[id], ord[e.to]);
            }
        }
        if (par == -1 && count >= 2) is_aps = true;
        if (is_aps) aps.push_back(id);
        return k;
    }
}

int main() {
    return 0;
}