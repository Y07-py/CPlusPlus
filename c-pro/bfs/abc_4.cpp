#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int W, H;

int dx[3] = {1, 0, -1};
int dy[3] = {1, 0, -1};

int field[110][110];
bool area[110][110];

int bfs(int sx, int sy) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(sx, sy));

    int total = 0;

    while (!qu.empty()) {
        pair<int, int> point = qu.front(); qu.pop();
        area[point.second][point.first] = true;
        int counter = 6;
        vector<bool> check(6, true);
        for (int i = 0; i < 3; i++) {
            int nx = point.first + dx[i];
            for (int j = 0; j < 3; j++) {
                int ny = point.second + dy[j];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                if (area[ny][nx]) continue;
                if ((i == 1 && j == 2) || (i == 2 && j == 2)) {
                    if (field[ny][nx] == 1) {
                        if (check[0]) {
                            counter--;
                            check[0] = false;
                        }
                    }
                } else if ((i == 0 && j == 2) || (i == 1 && j == 2)) {
                    if (field[ny][nx] == 1) {
                        if (check[1]) {
                            counter--;
                            check[1] = false;
                        }
                    }
                } else if ((i == 0 && j == 1)) {
                    if (field[ny][nx] == 1) {
                        if (check[2]) {
                            counter--;
                            check[2] = false;
                        }
                    }
                } else if (i == 2 && j == 1) {
                    if (field[ny][nx] == 1) {
                        if (check[3]) {
                            counter--;
                            check[3] = false;
                        }
                    }
                } else if ((i == 2 && j == 0) || (i == 1 && j == 0)) {
                    if (field[ny][nx] == 1) {
                        if (check[4]) {
                            counter--;
                            check[4] = false;
                        }
                    }
                } else if ((i == 1 && j == 0) || (i == 0 && j == 0)) {
                    if (check[5]) {
                        counter--;
                        check[5] = false;
                    }
                }
                qu.push(make_pair(nx, ny));
            }
        }
        total += counter;
    }
    return total;
}

int main() {
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> field[i][j];
            if (field[i][j]) {
                area[i][j] = false;
            } else area[i][j] = true;
        }
    }
    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!area[i][j]) res += bfs(j, i);
        }
    }
    cout << res << endl;
    return 0;
}