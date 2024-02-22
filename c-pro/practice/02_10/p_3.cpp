#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e8;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
    int D, N; cin >> D >> N;
    vector<int> T(D);
    for (int i = 0; i < D; i++) cin >> T[i];
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }
    vector<int> most_lower(D, inf);
    vector<int> most_larger(D, 0);
    for (int i = 0; i < D; i++) {
        int t = T[i];
        for (int j = 0; j < N; j++) {
            if (A[j] <= t && t <= B[j]) {
                chmin(most_lower[i], C[j]);
                chmax(most_larger[i], C[j]);
            }
        }
    }
    vector<vector<int> > dp(D+1, vector<int>(2, 0));
    for (int i = 0; i < D; i++) {
        dp[i+1][0] = max(dp[i][0] + abs(most_lower[i+1] - most_larger[i]), dp[i][1] + abs(most_lower[i+1] - most_larger[i]));
        dp[i+1][1] = max(dp[i][1] + abs(most_larger[i+1] - most_larger[i]), dp[i][0] + abs(most_larger[i+1] - most_lower[i]));
    }
    cout << max(dp[D-1][0], dp[D-1][1]) << endl;
    return 0;
}