#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N;
ll a[100010][3];
ll dp[100010][3];

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                chmax(dp[i+1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    ll res = 0;
    for (int i = 0l i < 3; i++) {
        chmax(res, dp[N][j]);
    }

    cout << res << endl;

    return 0;
}