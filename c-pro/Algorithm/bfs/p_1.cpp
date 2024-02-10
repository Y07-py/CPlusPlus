#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < N; i++) 
const int inf = 10000000010;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int N; cin >> N;
    vector<vector<char> > S(N, vector<char>(N));
    rep(i, N) rep(j, N) cin >> S[i][j];
    vector dis(N, vector(N, vector(N, vector(N, inf))));
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    rep(i, N) rep(j, N) if (S[i][j] == 'P') {
        if (x1 == -1) x1 = i, y1 = j;
        else x2 = i, y2 = j;
    }
    queue<array<int, 4> > que;
    dis[x1][y1][x2][y2] = 0;
    que.push({x1, y1, x2, y2});
    while (!que.empty()) {
        array<int, 4> ar = que.front(); que.pop();
        rep(d, 4) {
            array<int, 4> nxt = ar;
            nxt[0] += dx[d], nxt[1] += dy[d];
            if (0 > nxt[0] || nxt[0] >= N || nxt[1] < 0 || nxt[1] >= N) {
                nxt[0] = ar[0], nxt[1] = ar[1];
            }
            nxt[2] += dx[d], nxt[3] += dy[d];
            if (0 > nxt[2] || nxt[2] >= N || 0 > nxt[3] || nxt[3] >= N) {
                nxt[2] = ar[2], nxt[3] = ar[3];
            }
            if (dis[nxt[0]][nxt[1]][nxt[2]][nxt[3]] == inf) {
                dis[nxt[0]][nxt[1]][nxt[2]][nxt[3]] = dis[ar[0]][ar[1]][ar[2]][ar[3]] + 1
                que.push(nxt);
            }
        }
    }
    int ans = inf;
    rep(i, N) rep(j, N) ans = min(ans, dis[i][j][i][j]);
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}