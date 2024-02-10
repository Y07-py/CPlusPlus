#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int M, N, K; cin >> M >> N >> K;
    vector<string> joi(N);
    vector<vector<int> > vj(M+1, vector<int>(N+1, 0));
    vector<vector<int> > vo(M+1, vector<int>(N+1, 0));
    vector<vector<int> > vi(M+1, vector<int>(N+1, 0));
    for (int i = 0; i < M; i++) {
        cin >> joi[i];
        for (int j = 0; j < N; j++) {
            vj[i+1][j+1] = vj[i+1][j] + vj[i][j+1] - vj[i][j];
            vo[i+1][j+1] = vo[i+1][j] + vo[i][j+1] - vo[i][j];
            vi[i+1][j+1] = vi[i+1][j] + vi[i][j+1] - vi[i][j];
        }
    }
    return 0;
}