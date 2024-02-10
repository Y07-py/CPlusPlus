#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int INF = (1 << 20);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
    int N; cin >> N;
    vector<vector<int> > table(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
    vector<vector<int> > dp(N, vector<int>(N, INF));
    vector<vector<bool> > judge(N, vector<bool>(N, false));
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == k || j == k || i == j) continue;
                if (table[i][j] > table[i][k] + table[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                if (table[i][j] == table[i][k] + table[k][j]) {
                    judge[i][j] = true;
                }
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (judge[i][j]) continue;
            res += table[i][j];
        }
    }
    cout << res << endl;
    return 0;
}