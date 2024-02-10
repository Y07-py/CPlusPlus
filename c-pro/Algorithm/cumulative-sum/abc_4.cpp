#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX = 1010101;

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int> > CS(MAX, vector<int>(MAX));
    vector<vector<int> > CNT(MAX, vector<int>(MAX));
    CS[0][0] = 0;
    for (int i = 0; i < M; i++) {
        int L, R; cin >> L >> R;
        CNT[L][R]++;
    }
    for (int l = 1; l < N+1; l++) {
        for (int r = 2; r < N+1; r++) {
            CNT[l][r] += CNT[l][r-1];
        }
    }
    for (int i = 0; i < Q; i++) {
        int p, q; cin >> p >> q;
        cout << CS[q] - CS[p-1] << endl;
    }
    return 0;
}
