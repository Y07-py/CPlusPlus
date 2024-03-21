#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }
    vector<vector<bool> > dp(N+1, vector<bool>(1010101, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 101010; j++) {
            int a = A[i];
            int b = B[i];
            for (int s = 0; s < b+1; s++) {
                if (dp[i][j]) {
                    dp[i+1][j+a*s] = true;
                }
            }
        }
    }
    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}