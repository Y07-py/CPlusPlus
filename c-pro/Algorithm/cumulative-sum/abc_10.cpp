#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX = (1 << 21);

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<pair<int, int> > LR(M);
    vector<pair<int, int> > PQ(Q);
    vector<vector<int> > CS(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < M; i++) {
        int l, r; cin >> l >> r;
        CS[l][r]++;
    }
    for (int l = 1; l < N+1; l++) {
        for (int r = 2; r < N+1; r++) {
            CS[l][r] += CS[l][r-1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int p, q; cin >> p >> q;
        int res = 0;
        for (int l = p; l < q+1; l++) {
            res += CS[l][q];
        }
        cout << res << endl;
    }
    return 0;
}