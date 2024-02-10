#include <bits/stdc++.h>
using namespace std;
using Field = vector<vector<int> >;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int M, N;

Field Check;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cost = 0;

void dfs(pair<int, int> s, Field F, int now) {
    int x = s.first;
    int y = s.second;
    now++;
    Check[y][x] = 1;
    cost = max(cost, now);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (Check[ny][nx] > 0) continue;
        pair<int, int> point = make_pair(nx, ny);
        if (F[ny][nx] == 1) {
            dfs(point, F, now);
        }
    }
    Check[y][x] = 0;
}



int main() {
    cin >> M >> N;
    Field F;
    F.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> F[i][j];
        }
    }
    int ans = 0;
    Check.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (F[i][j] == 1) {
                pair<int, int> point = make_pair(j, i);
                dfs(point, F, 0);
            }
        }
    }
    cout << cost << endl;
    return 0;
}