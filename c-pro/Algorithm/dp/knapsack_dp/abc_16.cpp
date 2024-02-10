#include <bits/stdc++.h>
using namespace std;

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

    vector<vector<int> > V(D, vector<int>(2));

    for (int i = 0; i < D; i++) {
        int t = T[i];
        for (int j = 0; j < N; j++) {
            if (A[j] <= T && T <= B[j]) {
                int c = C[j];
                V[i][0] = min(V[i][0], c);
                V[i][1] = max(V[i][1], c);
            }
        }
    }

    vector<vector<int> > dp(D+1, vector<int>(2));
    for (int i = 0; i < D; i++) {
        dp[i+1][0] = max(dp[i][0] + abs(V[i+1][0] - V[i][0]), dp[i][1] + abs(V[i+1][0] - V[i][1]));
        dp[i+1][1] = max(dp[i][0] + abs(V[i+1][1] - V[i][0]), dp[i][1] + abs(V[i+1][1] - V[i][1]));
    }
    cout << max(dp[D][0], dp[D][1]) <<  endl;
    return 0
}