#include <bits/stdc++.h>
using namespace std;
static const int MAX = 100;
static const int INFITY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int> > adj[MAX];

void dijkstra() {
    priority_queue<pair<int, int>> PQ;
    int color[MAX];
    int d[MAX];
    for (int i = 0; i < n; i++) {
        d[i] = INFINITY;
        color[i] = WHITE;
    }

    d[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = GRAY;
    
    while (!PQ.empty()) {
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;
        color[u] = BLACK;

        if (d[u] < f.first * (-1)) continue;

        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            if (color[v] == BLACK) continue;
            if (d[v] > d[u] + adj[u][j].second) {
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }
}
