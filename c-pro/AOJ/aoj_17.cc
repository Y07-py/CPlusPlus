#include <bits/stdc++.h>
using namespace std;

static const int N = 100;
static const int INF = (1<<21);
int n, M[N][N];
int d[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    for (int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    int u;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0) continue;;
            if (d[v] != INF) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << 1 + 1 << " " << ( (d[i] == INF) ? (-1) : d[i]) << endl;
    }
}