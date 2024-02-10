#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > Field;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int N, M;

void dfs(int x, int y, int& counter, Field f) {
    f[y][x] = 0;
    counter++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (f[ny][nx] == 0) continue;
        if (f[ny][nx] == 1) {
            dfs(nx, ny, counter, f);
        }
    }
    counter--;
}

int main() {
    cin >> M >> N;
    Field field(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 0) continue;
            int tmp = 1;
            Field f = field;
            f[i][j] = 0;
            dfs(j, i, tmp, f);
            chmax(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}