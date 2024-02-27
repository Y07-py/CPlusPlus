#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e10;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<long long> > dis(N, vector<long long>(N, inf));
    for (int i = 0; i < N; i++) {
        dis[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        dis[a][b] = c;
    }

    long long ans = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                if (dis[i][j] != inf) ans += dis[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}