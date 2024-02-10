#include <bits/stdc++.h>
using namespace std;

int H, W, N;
char Field[1001][1001];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int bfs(int sx, int sy, int gx, int gy, int power, int res) {
    int area[1001][1001];
    queue<pair<int, int> > qu;
    qu.push(make_pair(sx, sy));

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            area[i][j] = 0;
        }
    }
    area[sy][sx] = res;
    bool flag = false;
    while (!qu.empty()) {
        pair<int, int> point = qu.front(); qu.pop();
        Field[point.second][point.first] = 'X';
        for (int i = 0; i < 4; i++) {
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (Field[ny][nx] == 'X') continue;
            area[ny][nx] = area[point.second][point.first] + 1;
            if (Field[ny][nx] - '0' >= 0 && Field[ny][nx] - '0' <= 9) {
                if (Field[ny][nx] - '0' == power) {
                    flag = true;
                    break;
                } else continue;
            }
            qu.push(make_pair(nx, ny));
        }
        if (flag) break;
    }
    cout << area[gx][gy] << endl;
    return area[gy][gx];
}

int main() {
    cin >> H >> W >> N;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> Field[i][j];
        }
    }
    int sx, sy;
    int gx, gy;
    vector<pair<int, int> > points(10);
    int counter = 0;
    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (Field[i][j] == 'S') {
                sx = j; sy = i;
            }
            if (Field[i][j] - '0' >= 0 && Field[i][j] - '0' <= 9) {
                points[Field[i][j] - '0'] = make_pair(j, i);
                counter++;
            }
        }
    }
    char clone[1001][1001];
    memcpy(clone, Field, sizeof(Field));
    int power = 1;
    for (int i = 0; i < counter; i++) {
        pair<int, int> point = points[i];
        res = bfs(sx, sy, point.first, point.second, power, res);
        power++;
        sx = point.first; sy = point.second;
        memcpy(Field, clone, sizeof(clone));
    }
    
    cout << res << endl;
    return 0;
}