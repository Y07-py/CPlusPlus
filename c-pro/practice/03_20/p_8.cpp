#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > node;
vector<bool> used;
int N;

void dfs(int s, int &cnt, int p=-1) {
    if (used[s]) return;
    used[s] = true;
    cnt++;
    if (cnt == N) return;
    for (int u: node[s]) {
        if (u == p) continue;
        dfs(u, cnt, s);
    }
}

int main() {
    int M; cin >> N >> M;
    node.resize(N);
    used.assign(N, false);

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    if (N-1 != M) {
        cout << "No" << endl;
        return 0;
    }

    int cnt = 0;
    dfs(0, cnt);
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            cout << "No" << endl;
            return 0;
        }
        if (node[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (cnt != N) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}