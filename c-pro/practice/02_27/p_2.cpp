#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dep;
vector<vector<int> > to;

void dfs(int v, int _dep = 0, int p=-1) {
    dep[v] = _dep;
    for (int u: to[v]) {
        if (u == p) continue;
        dfs(u, _dep+1, v);
    }
}

int main() {
    int N, Q; cin >> N >> Q;
    to.resize(N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dep.resize(N+1);
    dfs(0);

    for (int i = 0; i < Q; i++) {
        int c, d; cin >> c >> d;
        --c, --d;
        int ans = (dep[c]+dep[d])%2;
        if (ans == 0) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
    return 0;
}




