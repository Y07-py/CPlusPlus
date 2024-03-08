#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bfs(int H, int W, vector<string> C) {
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    vector<vector<bool> > used(H, vector<bool>(W, false));
    vector<vector<int> > cnt(H, vector<int>(W, -1));

    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    used[0][0] = 1;
    cnt[0][0] = 1;

    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        for (int i = 0; i < 2; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                if (used[ny][nx]) continue;
                if (C[ny][nx] == '.') {
                    used[ny][nx] = true;
                    cnt[ny][nx] = cnt[p.second][p.first] + 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(cnt[i][j], ans);
        }
    }
    return ans;
}

int main() {
    int H, W; cin >> H >> W;
    vector<string> C(H);
    for (int i = 0; i < H; i++) cin >> C[i];
    int ans = bfs(H, W, C);
    cout << ans << endl;
    return 0;
}