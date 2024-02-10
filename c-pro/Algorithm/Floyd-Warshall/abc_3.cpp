#include <bits/stdc++.h>
using namespace std;
static const int INF = (1 << 20);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int> > C(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> C[i][j];
        }
    }
    vector<vector<int> > field(10, vector<int>(10, INF));
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                chmin(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int n; cin >> n;
            if (n == -1) continue;
            ans += C[n][1];
        }
    }
    cout << ans << endl;
    return 0;
}