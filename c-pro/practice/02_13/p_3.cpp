#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> > A;
int H, W;
int ans = 0;

void solve(int x, int y, set<ll> s) {
    if (s.count(A[y][x])) return;
    s.insert(A[y][x]);
    if (x == W-1 && y == H-1) {
        ans++;
        return;
    }
    if (x+1 < W) solve(x+1, y, s);
    if (y+1 < H) solve(x, y+1, s);
}

int main() {
    cin >> H >> W;
    set<ll> numbers;
    A.assign(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    set<ll> s;
    solve(0, 0, s);
    cout << ans << endl;
    return 0;
}