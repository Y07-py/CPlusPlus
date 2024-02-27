#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > town(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        town[a].push_back(b);
    }

    int ans = 0;
    for (int v = 0; v < N;  v++) {
        stack<int> que;
        vector<int> used(N);
        used[v] = 1;
        ++ans;
        que.push(v);
        while (!que.empty()) {
            int u = que.top();
            que.pop();
            for (int t: town[u]) {
                if (used[t]) continue;
                ans++;
                used[t] = 1;
                que.push(t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}