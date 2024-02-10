#include <bits/stdc++.h>
using namespace std;
static const int INF = (1 << 21);
typedef vector<string> Field;
typedef vector<vector<int> > Area;

int R, C;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
Field field(R+1);

int bfs(int sx, int sy, int gx, int gy) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(sx, sy));
    int area[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            area[i][j] = 0;
        }
    }

    while(!qu.empty()) {
        pair<int, int> point = qu.front(); 
        qu.pop();
        field[point.second][point.first] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];
            if (0 > nx || nx >= C || ny < 0 || ny >= R) continue;
            if (field[ny][nx] == '#') continue;
            qu.push(make_pair(nx, ny));
            area[ny][nx] = area[point.second][point.first] + 1;
        }
    }
    return area[gy][gx];
}

int main() {
    cin >> R >> C;
    int sy, sx; cin >> sy >> sx;
    int gx, gy; cin >> gy >> gx;
    
    for (int i = 0; i < R; i++) {
        cin >> field[i];
    }
    sx--; sy--; gx--; gy--;
    int res = bfs(sx, sy, gx, gy);
    cout << res << endl;
    return 0;
}