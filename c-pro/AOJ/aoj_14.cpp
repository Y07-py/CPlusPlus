#include <bits/stdc++.h>
using namespace std;
static const int N = 100;

int lcs(string X, string Y) {
    int C[N+1][N+1];
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for (int i = 0; i <= m; i++) C[i][0] = 0;
    for (int j = 1; j <= n; j++) C[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = max(C[i][j-1], C[i-1][j]);
            }
            maxl = max(maxl, C[i][j]);
        }
    }
    return maxl;
}



int main() {
    int n; cin >> n;
    int F[50];
    F[0] = F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    cout << F[n] << endl;
    return 0;
}