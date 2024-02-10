#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e8;
#define rep(i, n) for (int i = 0; i < n; i++);

int dis(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2)**2 + (y1 - y2)**2);
}

int main() {
    int N; cin >> N;
    ll checker[5050][5050] = {inf};
    vector<pair<int, int> > position(N);
    rep(i, N) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        checker[x][y] = 1;
        position[i] = make_pair(x, y);
    }
    ll res = 0;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            pair<int, int> p1 = position[i];
            pair<int, int> p2 = position[j];
            int d = dis(p1.first, p1.second, p2.first, p2.second);
            int dx = abs(p1.first - p2.first);
            int dy = abs(p1.second - p2.second);
            int nx1_r = p1.first + dy;
            int ny1_r = p1.second - dx;
            int nx1_l = p1.first - dy;
            int ny1_l = p1.second + dy;
            int nx2_r = p2.first - dy;
            int ny2_r = p2.second + dx;
            int nx2_l = p2.first + dy;
            int ny2_l = p2.second - dx;
            if (0 <= nx1_r && nx1_r < 5000 && 0 <= ny1_r && ny1_r < 5000 && 0 <= nx2_l && nx2_l < 5000 && 0 <= ny2_l && ny2_l < 5000) {
                if (checker[nx1_r][ny1_r] != inf) {
                    if (checker[nx2_l][ny2_l] != inf) {
                        res = max(res, d**2);
                    }
                }
            }
            if (0 <= nx1_l && nx1_l < 5000 && 0 <= ny1_l && ny1_l < 5000 && 0 <= nx2_r && nx2_r < 5000 && 0 <= ny2_r && ny2_r < 5000) {
                if (checker[nx1_l][ny1_l] != inf) {
                    if (checker[nx2_r][ny2_r] != inf) {
                        res = max(res, d**2);
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}