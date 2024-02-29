#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e7;

int N;
vector<vector<int> > tour;
vector<int> ans;

void dfs(int v, int p = -1) {
    ans.push_back(v);
    for (int u: tour[v]) {
        if (u == p) continue;
        dfs(u, v);
        ans.push_back(v);
    }
}

int main() {
    cin >> N;
    tour.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        tour[a].push_back(b);
        tour[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        sort(tour[i].begin(), tour[i].end());
    }
    dfs(0);
    for (int v: ans) {
        cout << v+1 << " ";
    }
    cout << endl;
    return 0;
}