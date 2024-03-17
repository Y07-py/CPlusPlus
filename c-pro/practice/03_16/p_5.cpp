#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > town;


void dfs(int v, vector<bool> &used) {
    if (used[v]) return;
    used[v] = true;
    for (int u: town[v]) dfs(u, used);
}

int main() {
    int N, M; cin >> N >> M;
    town.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        town[a].push_back(b);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<bool> used(N, false);
        dfs(i, used);
        for (int j = 0; j < N; j++) {
            if (used[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}