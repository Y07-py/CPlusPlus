#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > to(N);
    vector<int> deg(N);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        deg[b]++;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) pq.push(i);
    }
    vector<int> ans;

    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        ans.push_back(v);
        for (int u: to[v]) {
            deg[u]--;
            if (deg[u] == 0) pq.push(u);
        }
    }
    if (ans.size() != N) cout << -1 << endl;
    else {
        for (int v: ans) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}