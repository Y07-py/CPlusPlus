#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;

template<class T> inline void chmin(T&a, T b) {if (a > b) a = b;};

int main() {
    int N; cin >> N;
    int X, Y; cin >> X >> Y;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<vector<int> > > dp(301, vector<vector<int> >(301, vector<int>(301, inf)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int tak = 0; tak < X+1; tak++) {
            for (int tai = 0; tai < Y+1; tai++) {
                if (dp[i][tak][tai] < inf) {
                    dp[i+1][tak][tai] = min(dp[i+1][tak][tak], dp[i][tak][tai]);
                    dp[i+1][min(tak + A[i], X)][min(tai + B[i], Y)] = min(dp[i+1][min(tak + A[i], X)][min(tai + B[i], Y)], dp[i][tak][tai] + 1);
                }
            }
        }
    }

    if (dp[N][X][Y] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[N][X][Y] << endl;
    }
    return 0;
}