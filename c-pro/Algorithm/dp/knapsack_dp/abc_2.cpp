#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1LL << 60

int main() {
    int D, N; cin >> D >> N;
    vector<int> temps(D);
    for (int i = 0; i < D; i++) cin >> temps[i];
    vector<vector<int> > clothes(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < 3; i++) {
            int a; cin >> a;
            clothes[i].push_back(a);
        }
    }
    vector<vector<int> > dp(D, vector<int>(2));

    vector<vector<int> > x(D, vector<int>(2));
    for (int i = 0; i < D; i++) {
        x[i][0] = 101;
        x[i][1] = -1;
    }
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            if (clothes[j][0] <= temps[i] && clothes[j][1] >= temps[i]) {
                x[i][0] = min(x[i][0], clothes[j][2]);
                x[i][1] = max(x[i][1], clothes[j][2]);
            }
        }
    }

    for (int i = 0; i < D - 1; i++) {
        dp[i+1][0] = max(abs(x[i+1][0] - x[i][0]) + dp[i][0], abs(x[i+1][0] - x[i][1]) + dp[i][1]);
        dp[i+1][1] = max(abs(x[i+1][1] - x[i][0]) + dp[i][0], abs(x[i+1][1] - x[i][1]) + dp[i][1]);
    }

    cout << max(dp[D-1][0], dp[D-1][1]) << endl;
    return 0;
}