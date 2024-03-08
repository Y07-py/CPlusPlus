#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > cnt;

bool dfs(int v, int p, vector<int> used) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int u: cnt[v]) {
        if (used[u]) continue;
        dfs(u, v, used);
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    cnt.resize(N);
    for (int i=0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        cnt[a].push_back(b);
        cnt[b].push_back(a);
    }
    bool flag = true;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i].size() > 2) flag = false;
        vector<int> used(N, 0);
        if (!dfs(i, -1, used)) flag = false;

    }
    if (flag && count == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}