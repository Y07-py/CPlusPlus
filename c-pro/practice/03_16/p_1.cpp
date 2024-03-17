#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> > A;
int H, W;
int ans = 0;
void dfs(int x, int y, set<ll> st) {
    if (st.find(A[y][x]) != st.end()) return;
    if (x == W-1 && y == H-1) {
        ans++;
        return;
    }
    st.insert(A[y][x]);
    if (x+1 < W) dfs(x+1, y, st);
    if (y+1 < H) dfs(x, y+1, st);
}

int main() {
    cin >> H >> W;
    A.assign(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    set<ll> st;
    dfs(0, 0, st);
    cout << ans << endl;
    return 0;
}