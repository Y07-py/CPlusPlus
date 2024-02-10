#include <bits/stdc++.h>
using namespace std;
static const int MAX = 100;
static const int INFINITY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim() {
    int u, minv;
    int d[MAX], p[MAX], color[MAX];

    for (int i = 0; i < n; i++) {
        d[i] = INFINITY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while (1) {
        minv = INFINITY;
        u = -1;
        for (int i = 0; i < n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;
        color[u] = BLACK;
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && M[u][v] != INFINITY) {
                if (d[v] > M[u][v]) {
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0 ; i < n; i++) {
        if (p[i] != -1) sum += M[i][p[i]]; {
            int e; cin >> e;
            M[i][j] = (e == -1) ? INFINITY : 0;
        }
    }
}


int main() {

    return 0;
}