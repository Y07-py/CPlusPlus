#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > node;
deque<int> dq;
vector<int> ans;
int X, Y;

bool dfs(int v, int p=-1) {
    if (v == X) {
        ans.push_back(v);
        return true;
    }
    for (int u: node[v]) {
        if (u == p) continue;
        if (dfs(u, v)) {
            ans.push_back(v);
            return true;
        }
    }
    return false;
}

int main() {
    int N; cin >> N >> X >> Y;
    Y--;
    X--;
    node.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    if (dfs(Y)) {
        for (int u: ans) {
            cout << u+1 << " ";
        }
        cout << endl;
    }
    return 0;
}