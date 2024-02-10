#include <bits/stdc++.h>
using namespace std;
#define loop(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i>= 0; i--)
using ll = long long;
const int INF = 1LL << 20;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

int V, E;
int G[20][20];
int dp[5000][20];

int rec(int S, int v) {
    if (S == 0) {
        if (v == 0) {
            return 0;
        } else {
            return INF;
        }
    }
    if ((S & (1 << v)) == 0) {
        return INF;
    }

    int &ret = dp[S][v];
    if (ret != 0) return ret;

    ret = INF;
    REP(U, V) { chmin(ret, rec(S ^ (1 << v), u) + G[u][v]); }
    return ret;
}