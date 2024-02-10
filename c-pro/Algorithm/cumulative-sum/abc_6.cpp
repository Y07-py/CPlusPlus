#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll H, W, K, V; cin >> H >> W >> K >> V;
    vector<vector<ll> > area(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> area[i][j];
        }
    }

    vector<vector<ll> > CS(H+1, vector<ll>(W+1), 0);
    for (int i = 0; i < H+1; i++) {
        for (int j = 0; j < W+1; j++) {
            CS[i+1][j+1] = CS[i+1][j] + CS[i][j+1] - CS[i][j] + area[i][j];
        }
    }

    for (int i = 0; i < )

    return 0;
}
