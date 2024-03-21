#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > node;
vector<bool> used;
vector<int> roop;

void dfs(int u, int &ans, int p=-1) {
    if (used[u]) {
        ans++;
        return;
    }
    used[u] = true;
    for (int v: node[u]) {
        if (v == p) continue;
        dfs(v, ans, u);
    }
}

int main() {
    int N, M; cin >> N >> M;
    node.resize(N);
    used.assign(N, false);
    roop.assign(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int ans = 0;
    dfs(0, ans);
    cout << M - N + ans << endl;
    return 0;
}