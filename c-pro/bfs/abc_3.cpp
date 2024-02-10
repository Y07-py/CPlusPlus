#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int Field[1001][1001];
char Area[1001][1001];

int H, W, N;

int bfs(int sx, int sy, int gx, int gy, int power, int res) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(sx, sy));
    bool flag = false;
    Field[sy][sx] = res;
    while (!qu.empty()) {
        pair<int, int> point = qu.front(); qu.pop();
        Area[point.second][point.first] = 'X';
        for (int i = 0; i < 4; i++) {
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];
            if (0 > nx || nx >= W || ny < 0 || ny >= H) continue;
            if (Area[ny][nx] == 'X') continue;
            Field[ny][nx] = Field[point.second][point.first] + 1;
            if (Area[ny][nx - '0' >= 0 && Area[ny][nx] - '0' <= 9]) {
                if (Area[ny][nx] - '0' == power) {
                    flag = true;
                    break;
                }
            }
            qu.push(make_pair(nx, ny));
        }
        if (flag) break;
    }
    return Field[gy][gx];
}

int main() {
    cin >> H >> W >> N;
    int sx, sy;
    vector<pair<int, int> > points(10);
    int size = 0;
    int res = 0;
    int power = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> Area[i][j];
            if (Area[i][j] == 'S') {
                sx = j; sy = i;
            }
            if (Area[i][j]- '0' >= 0 && Area[i][j] - '0' <= 9) {
                points[Area[i][j] - '0'-1] = make_pair(j, i);
                size++;
            }
        }
    }
    char clone[1001][1001];
    memcpy(clone, Area, sizeof(Area));
    for (int i = 0; i < size; i++) {
        pair<int, int> point = points[i];
        res = bfs(sx, sy, point.first, point.second, power, res);
        power++;
        sx = point.first; 
        sy = point.second;
        memcpy(Area, clone, sizeof(clone));
    } 
    cout << res << endl;
    return 0;
}