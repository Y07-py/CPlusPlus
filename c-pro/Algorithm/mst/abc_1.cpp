#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int INF = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int MAX = 100;

int N, M[MAX][MAX];

int prim() {
    int u, minv;
    int d[MAX], p[MAX], color[MAX];

    for (int i = 0; i < N; i++) {
        d[i] = INF;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while (1) {
        minv = INF;
        u = -1;
        for (int i = 0; i < N; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;
    }
}

int main() {

    return 0;
}