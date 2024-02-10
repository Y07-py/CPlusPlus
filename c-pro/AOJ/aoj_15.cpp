#include <bits/stdc++.h>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visi(int u) {
    int v;
    color[u] = GRAY;
    d[u]++;
    for (v = 0; v < n; v++) {
        if (M[u][v] == 0) continue;
        if (color[v] == WHITE) {
            dfs_visi(v);
        }
    }
    color[v] = BLACK;
    f[u]++;
}

int main() {
    return 0;
}