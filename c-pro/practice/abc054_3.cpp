#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
using Graph = vector<vector<int>>;
Graph G;

void solve(int v, vector<bool>& node, int& res, int counter) {
    node[v] = true;
    counter++;
    if (counter == N) {
        counter = 0;
        res++;
        node[v] = false;
        return;
    }
    for (auto e: G[v]) {
        if (node[e]) {
            continue;
        }
        solve(e, node, res, counter);
    }
    node[v] = false;
}


int main() {
    cin >> N >> M;
    vector<bool> node(N, false);
    G.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    int res = 0;
    int counter = 0;
    solve(0, node, res, counter);
    
    cout << res << endl;
    return 0;
}